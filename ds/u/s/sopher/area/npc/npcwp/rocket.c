inherit F_BULLET;
inherit ITEM;
void create()
{

set_name("���b�u",({"rockets"}));
if( clonep() )
set_default_object(__FILE__);
set("unit", "�T");
set("value", 60);
set_weight(1220);
set("amount",3);
set("bullet/damage",22);
set("bullet/unit","�T");
set("bullet/name","���b");
set("type","small");
setup();
}
