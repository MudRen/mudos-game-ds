#include <ansi.h>
inherit ITEM;
inherit F_BULLET;
void create()
{
set_name("�u��",({"clip"}));
        if( clonep() )
           set_default_object(__FILE__);
        else {
        set("unit", "��");
        set("long","�O�@�Ӧh�γ~�����ݻs�u��,�C�@�ռu�����˦�10�o�l�u�C\n");
        }
      set("value", 400);
   set_weight(1000);
set("amount",10);                //�u�Ķq
  set("bullet/damage",20);        //���ˤO
set("bullet/unit","�o");        //�u�ĳ��
set("bullet/name","�l�u");      //�u�ĦW��
set("type","clip");            //�l�u����
setup();
}
