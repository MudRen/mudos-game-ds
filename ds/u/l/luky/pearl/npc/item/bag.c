//bag.c by luky
#include <ansi.h>
inherit ITEM;
inherit F_AUTOLOAD;
void create()
{
seteuid(getuid());
set_name("�Ȧ�I�]",({"travel bag","bag"}));
        if( clonep() )
           set_default_object(__FILE__);
        else {
        set("unit", "��");
        set("long",HIG"�@�ӥi�ѮȦ�̦s���������U�l�C(put �� in bag �άOget �� from bag)"NOR"\n");
        }
set("value", 3000);
set_weight(4720);
set("amount",1);
set("usage","�Ψө�m�@���H����a�����~.");
set_max_encumbrance(21010);
this_object()->set_max_encumbrance(21010);
}

