//bag.c by luky
#include <ansi.h>
inherit ITEM;
inherit F_AUTOLOAD; //<--���ζ�?
void create()
{

set_name("�Ȧ�I�]",({"travel bag","bag"}));
        if( clonep() )
           set_default_object(__FILE__);
        else {
        set("unit", "��");
        set("long",@LONG
�@�ӥi�ѮȦ�̦s���������U�l�C(put �� in bag �άOget �� from bag)
LONG
);
        }
	set("value", 150);
	set("volume", 5);
	set_weight(1820);
	set("amount",1);
	set("usage","�Ψө�m�@���H����a�����~.");
	set_max_encumbrance(50000);
	set_max_capacity(100);
	setup();
}

int query_autoload() { return 1; }