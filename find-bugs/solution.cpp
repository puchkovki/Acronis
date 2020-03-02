* @brief
*		Find errors and decrease probability of getting errors of the same kind in the future
*		This piece of code won't compile and it doesn't describe an entire algorithm: just part of some page storage
*
* @author
*		AnnaM
*/

#include <Windows.h>
#include <stdio.h>

enum PAGE_COLOR
{
	PG_COLOR_GREEN = 1, /* page may be released without high overhead */
	PG_COLOR_YELLOW, /* nice to have */
	PG_COLOR_RED	/* page is actively used */
};


/**
 * UINT Key of a page in hash-table (prepared from color and address)
 */
union PageKey
{
	struct
	{
        CHAR	cColor: 8;
		UINT	cAddr: 24;
	};

	UINT	uKey;
};


/* Prepare from 2 chars the key of the same configuration as in PageKey */
#define CALC_PAGE_KEY( Addr, Color )	(  (Color) + (Addr) << 8 ) //№1: нужно бы скобочки вокруг битовой операции


/**
 * Descriptor of a single guest physical page
 */
struct PageDesc
{
	PageKey			uKey;	

	/* list support */
	PageDesc		*next, *prev;
};

#define PAGE_INIT( Desc, Addr, Color )              \
    {                                               \
        (Desc).uKey = CALC_PAGE_KEY( Addr, Color ); \
        (Desc).next = (Desc).prev = NULL;           \
    }
        

/* storage for pages of all colors */
static PageDesc* PageStrg[ 3 ];

void PageStrgInit()
{
	memset( PageStrg, 0, sizeof(&PageStrg) ); //3 байта
}

PageDesc* PageFind( void* ptr, char color )
{
	for( PageDesc* Pg = PageStrg[color]; Pg; Pg = Pg->next );//Опечатка мб — точка с запятой лишняя
        if( Pg->uKey == CALC_PAGE_KEY(ptr,color) )
            return Pg;                                                                                                                                     
    return NULL;
}

PageDesc* PageReclaim( UINT cnt )
{
	UINT color = 0;
	PageDesc* Pg;
	while( cnt )
	{
		Pg = Pg->next;
		PageRemove( PageStrg[ color ] ); //не объявлена функция
		cnt--;
		if( Pg == NULL )
		{
			color++;//возможен выход за допустимые размеры (3)
			Pg = PageStrg[ color ];
		}
	}
}
            
PageDesc* PageInit( void* ptr, UINT color )
{
    PageDesc* pg = new PageDesc;
    if( pg )
        PAGE_INIT(&pg, ptr, color);// * вместо & и лишняя ; снова
    else
        printf("Allocation has failed\n");
    return pg;
}

/**
 * Print all mapped pages
 */
void PageDump()
{
	UINT color = 0;
	#define PG_COLOR_NAME(clr) #clr
	char* PgColorName[] = 
	{
		PG_COLOR_NAME(PG_COLOR_RED),
		PG_COLOR_NAME(PG_COLOR_YELLOW),
		PG_COLOR_NAME(PG_COLOR_GREEN)
	};

	while( color <= PG_COLOR_RED )
	{
		printf("PgStrg[(%s) %u] ********** \n", color, PgColorName[color] );
		for( PageDesc* Pg = PageStrg[++color]; Pg != NULL; Pg = Pg->next )
		{
			//несуществеющее поле uAddr структуры
			if( Pg->uAddr = NULL )
				continue;
			//несуществеющее поле uAddr и uKey структуры
			printf("Pg :Key = 0x%x, addr %p\n", Pg->uKey, Pg->uAddr );
		}
	}
	#undef PG_COLOR_NAME
}