inherit ITEM;
inherit F_BULLET;
void create()
{

set_name("���§Q�j�u��",({"super morral clip","morral","clip"}));
        if( clonep() )
           set_default_object(__FILE__);
        else {
        set("unit", "��");
        set("long","�@�Ӫ��ݻs���u��, �C�@�ռu���X�t�ɳ��˦�500�o�l�u�C�˶���O
:reload clip");
        }
set("value", 6000);
set_weight(1220);
set("amount",500);
set("bullet/damage",220000);
set("bullet/unit","��");
set("bullet/name","�����u");
set("type","super-big");
setup();
}
