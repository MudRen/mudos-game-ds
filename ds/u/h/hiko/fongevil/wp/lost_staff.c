#include <ansi.h>
#include <weapon.h>
inherit STAFF;
void create()
{
        set_name("��ߧ�",({"lost heart staff","staff"}));
        set_weight(6000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
               set("unit", "��");
               set("long", "�o�O�@��ѹӦa����һs�����A���H��𤣴����Pı�C\n");
               set("volume",5);
               set("value",6000);
               set("material", "gem");
               set("limit_str",20);
               set("limit_int",15);
               set("limit_con",20);
              
          }
   set("weapon_prop/int",3);
   set("weapon_prop/str",1);
   set("weapon_prop/hit",8);
   init_staff(45);
   setup();
}

