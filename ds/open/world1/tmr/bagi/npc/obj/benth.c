inherit ITEM;

void create()
{
	set_name("老人根",({"millettia nitida benth","benth"}) );
	set_weight(100);
	set("long",@long
老人根多生於山谷疏林或密林中，其藥用藤莖。四季可採，但以深秋
採為好。其味甘苦，性溫，可補血行血，通經活絡。為豆科攀援狀灌木，
幼枝有�蛈漟u柔毛，
long
);
	if(clonep() )
		set_default_object(__FILE__);
	else
	{
		set("unit","株");
		set("value",80);
	}
	setup(); 
}