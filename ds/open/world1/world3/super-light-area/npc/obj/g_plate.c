#include <ansi.h>
inherit ITEM;
void create() 
{
          set_name(HIY"���P"NOR,({"gold plate","plate"}) );
           set("long","�@�����q�l�޽u���������P�A�����D��J�쨭��(install plate)�̷|�o��ԣ�ơI\n");
               set("value",2000);
          set_weight(2000);
          if(clonep() ) 
            set_default_object(__FILE__);
           else {
          set("unit","��");
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
  write(HIW"���P�w�w�����i���餤....."HIC"�w�˧���\n"NOR);
    destruct(ob);
  return 1;
}


