//bag.c by luky
inherit ITEM;
#include <ansi.h>
inherit F_BULLET;
void create()
{

set_name("�l�u",({"psitol clip","clip"}));
        if( clonep() )
           set_default_object(__FILE__);
        else {
        set("unit", "��");
        set("long","�o�O��j���u�E�C�˶���O:(reload clip)\n");
        }
set("value", 800);
set_weight(1220);
set("amount",15);		//�u�Ķq
set("bullet/damage",25);	//���ˤO
set("bullet/unit","��");	//�u�ĳ��
set("bullet/name","�E��");	//�u�ĦW��
set("type","laser bolt");		//�l�u����
setup();
}

