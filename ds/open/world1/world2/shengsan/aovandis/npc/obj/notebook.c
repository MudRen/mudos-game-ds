// 筆記型電腦
inherit ITEM;

void create()
{
    set_name("英文翻譯機",({"english translator","translator"}) );
  set("long",@LONG
一部小小的掌上型中英文翻譯機。
LONG
);
	set_weight(15000);
	if(clonep() )
		set_default_object(__FILE__);
	else
	{
set("value",3000);
		set("unit","台");   //luky
set("material", "iron");
	}
	setup();
}

int do_use(object me,string arg)
{
 if(query("time")<1) 
 {
      tell_object(me,"這台電腦已經沒電了!\n");	
      return 1;
 }
 if(arg!="computer") return 0;
 
 tell_object(me,"筆記電腦發出一聲慘叫: 口圭∼口里∼口列∼∼\n要當機了，自己保重吧。\n");
 return 1;
}
