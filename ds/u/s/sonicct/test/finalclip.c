#include <ansi.h>
inherit ITEM;
inherit F_BULLET;
void create()
{

set_name(HIC"�׵��෽��"NOR,({"sun clip","sun","clip"}));
        if( clonep() )
           set_default_object(__FILE__);
        else {
        set("unit", "��");
        set("long","�@�Ӳ׵��෽��, �C�@�ղ׵��෽���X�t�ɳ��˦�100�կ෽�C�˶���O:(reload clip)\n");
        }
        set("value", 10000);
        set_weight(10000);
        set("amount",100);                
        set("bullet/damage",10000);        
        set("bullet/unit","��");        
        set("bullet/name","�෽");     
        set("type","enegry");      
        setup();
}