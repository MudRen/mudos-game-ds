inherit ITEM;
inherit F_BULLET;
void create()
{

set_name("�W�źj�u��",({"super bullet clip","bullet","clip"}));
        if( clonep() )
           set_default_object(__FILE__);
        else {
        set("unit", "��");
        set("long","�@�Ӫ��ݻs���u��, �C�@�ռu���X�t�ɳ��˦�500�o�l�u�C�˶���O
:reload clip");
        }
set("value", 600);
set_weight(1220);
set("amount",500);
set("bullet/damage",2200);
set("bullet/unit","�o");
set("bullet/name","���u");
set("type","super-big");
setup();
}
