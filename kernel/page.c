#include <target/page.h>

struct page *page_empty = NULL;
struct page **page_free_list = &page_empty;
bool page_early = true;

void page_free(caddr_t address)
{
	struct page *page = \
		(struct page *)ALIGN((uintptr_t)address, PAGE_SIZE-1);

	page->next = *page_free_list;
	*page_free_list = page;
}

caddr_t page_alloc(void)
{
	struct page *page;

	page = *page_free_list;
	*page_free_list = page->next;
	return (caddr_t)page;
}

caddr_t page_alloc_zeroed(void)
{
	caddr_t page = page_alloc();

	if (page)
		memory_set(page, 0, PAGE_SIZE);
	return page;
}

void page_late_init(void)
{
	/* TODO: convert page allocator to VA based */
	page_early = false;
}

void page_early_init(caddr_t base, pfn_t nr_pages)
{
	pfn_t pfn, pfn_start = page_to_pfn(base);
	struct page **last_page, *page;

	/* The lower pages are used for early page table allocation. */
	last_page = page_free_list;
	for (pfn = 0; pfn < nr_pages; pfn++) {
		page = pfn_to_page(pfn + pfn_start);
		page->next = NULL;
		*last_page = page;
		last_page = &page->next;
	}
}
