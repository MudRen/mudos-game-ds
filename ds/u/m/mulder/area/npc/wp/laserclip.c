//bag.c by luky
inherit ITEM;
#include <ansi.h>
inherit F_BULLET;
void create()
{

set_name(HIG"�E���j�෽��"NOR,({"laser clip","laser","clip"}));
        if( clonep() )
           set_default_object(__FILE__);
        else {
        set("unit", "��");
        set("long","�o�O�E���j���෽�C�˶���O:(reload clip)\n");
        }
set("value", 400);
set_weight(1220);
set("amount",10);		//�u�Ķq
set("bullet/damage",35);	//���ˤO
set("bullet/unit","��");	//�u�ĳ��
set("bullet/name","�E��");	//�u�ĦW��
set("type","laser");		//�l�u����
setup();
}

