inherit F_BULLET;
inherit ITEM;
void create()
{

set_name("��j�u�X",({"clip"}));
if( clonep() )
set_default_object(__FILE__);
set("unit", "�o");
set("value", 60);
set_weight(500);
set("amount",12);
set("bullet/damage",22);
set("bullet/unit","�o");
set("bullet/name","M-6235�l�u");
set("type","small");
setup();
}
