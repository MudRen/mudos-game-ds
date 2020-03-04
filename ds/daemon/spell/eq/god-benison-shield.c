
//-by tmr- PM 11:35 2000/1/24
//update 2000/4/7 -By tmr-

#include <armor.h>
#include <ansi.h>
inherit SHIELD;

int update_shield(object me,int sk,int inn);
void destruct_shield(object me);

void create()
{
        set_name(CYN"神武天盾"NOR,({"god shield","shield","god-benison-shield" }) );
        set("long","此物只應天上有，人間那得幾回見。\n");
        set_weight(1);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
        set("unit", "件" );
        set("armor_prop/armor", 1);
        set("material","diamond");
        set("volme",0);
        set("value",0);  //add by -Acme-
        set("no_sell",1);
        set("no_get",1);
        set("no_drop",1);
        }
        setup();
}

int update_shield(object me,int sk,int inn)
{
        object ob;
        int i;

        ob=this_object();
        
        i=sk/2; //        i=(sk*3+inn)/2;

        //設定物理防禦力
        ob->set("armor_prop/armor", i ); 
        //設定法術防禦力
        if(sk>50) 
               ob->set("armor_prop/shield", i );
//附加屬性
       if( sk>80 )
        {
                ob->set("armor_prop/int", 2 );
//               ob->set("armor_prop/dex", -1 );
        }
        call_out("destruct_shield",300,me);
        return 1;
}

void destruct_shield(object me)
{
        if(!me) return;
        if(!this_object() ) return;
        message_vision("$N手中的神武盾化成一陣煙霧，消失不見了。\n",me);
        destruct(this_object() );
        return; 
}


