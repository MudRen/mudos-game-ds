inherit ITEM;

void create()
{
    set_name("通識百科全書", ({"encyclopaedia book", "book"}));
    set_weight(1000);
	set("long",@long
這是一本厚達千頁的大部頭書，詳細記載這個世界上的基本知識，當
然必須具有足夠的學識，才能完全了解此書的內容。
long
	);
		if ( clonep() )
  			 set_default_object(__FILE__);
  		else {
	        set("unit", "本");
	        set("value", 100);	
	    }
    setup();
}

