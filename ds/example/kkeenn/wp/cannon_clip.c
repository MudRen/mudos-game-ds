inherit ITEM;
inherit F_BULLET;
void create()
{

set_name("�����l�u��",({"firestrom clip","clip"}));
        if( clonep() )
           set_default_object(__FILE__);
        else {
        set("unit", "��");
        set("long","�@�����ݻs������, �C�@���������t����5�o�෽�C\n");
        }
        set("value", 1000);
        set_weight(1500);
        set("amount",5);
        set("bullet/damage",60);
        set("bullet/unit","��");
        set("bullet/name","�����l����");   
        set("type","firestorm"); 
        setup();
         }

