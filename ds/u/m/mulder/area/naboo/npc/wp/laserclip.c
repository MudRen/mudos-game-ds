#include <ansi.h>
inherit ITEM;
inherit F_BULLET;
void create()
{

	set_name(HIC"�E���෽��"NOR,({"laster clip","laser","clip"}));
        if( clonep() )
           set_default_object(__FILE__);
        else {
        set("unit", "��");
        set("long","�@�ӿE���෽��, �C�@�տE���෽���X�t�ɳ��˦�20���E���C�˶���O:(reload clip)\n");
        set("value", 1200);
        set_weight(500);
        set("amount",20);                
        set("bullet/damage",30);        
        set("bullet/unit","��");        
        set("bullet/name","�E��");     
        set("type","energy");      
        }
        setup();
}   