//bag.c by luky
#include <ansi.h>
inherit ITEM;
inherit F_AUTOLOAD;
void create()
{

set_name("�Ȧ�I�]",({"travel bag","bag"}));
        if( clonep() )
           set_default_object(__FILE__);
        else {
        set("unit", "��");
        set("long",HIG"�@�ӥi�ѮȦ�̦s���������U�l�C(put �� in bag �άOget �� from bag)"NOR"\n");
        }
set("value", 50);
set_weight(1820);
set("amount",1);
set("usage","�Ψө�m�@���H����a�����~.");
set_max_encumbrance(10000);
this_object()->set_max_encumbrance(10000);
setup();
}

