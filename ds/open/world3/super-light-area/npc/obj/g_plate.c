#include <ansi.h>
inherit ITEM;
void create() 
{
          set_name(HIY"金牌"NOR,({"gold plate","plate"}) );
           set("long","一面有電子管線的虛擬金牌，不知道輸入到身體(install plate)裡會發生啥事！\n");
               set("value",2000);
          set_weight(2000);
          if(clonep() ) 
            set_default_object(__FILE__);
           else {
          set("unit","面");
}
setup();
}
void init()
{
        add_action("do_install","install");
}
int do_install(string arg)
{
       object me,ob;
        if( !this_object() ) return 0;        
        if( !this_object()->id(arg) ) return 0; 
       ob=this_object();
       me=this_player();
  me->add("award/plate",1);
  write(HIW"金牌緩緩的飛進身體中....."HIC"安裝完成\n"NOR);
    destruct(ob);
  return 1;
}


