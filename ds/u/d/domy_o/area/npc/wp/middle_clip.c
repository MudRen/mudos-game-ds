inherit ITEM;
inherit F_BULLET;
void create()
{

set_name("�����u��",({"middle clip","clip"}));
        if( clonep() )
           set_default_object(__FILE__);
        else {
        set("unit", "��");
        set("long","�@�Ӥ����u��10�o�C�˶���O:(reload clip)\n");
        }
set("value", 40);
set_weight(1220);
set("amount",10);
set("bullet/damage",40);
set("bullet/unit","�o");
set("bullet/name","�l�u");
set("type","middle");
setup();
}

