inherit ITEM;
inherit F_BULLET;
void create()
{

set_name("�̮�60�u��",({"mag clip","clip"}));
        if( clonep() )
           set_default_object(__FILE__);
        else {
        set("unit", "��");
        set("long","�@�Ӫ��ݻs���u��, �C�@�ռu�����˦�10�o�l�u�C\n");
        }
        set("value", 800);
        set_weight(500);
        set("amount",10);
        set("bullet/damage",25);
        set("bullet/unit","�o");
        set("bullet/name","�l�u");   
        set("type","mag"); 
        setup();
         }

