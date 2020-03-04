
//-by tmr- PM 11:35 2000/1/24
//update 2000/4/7 -By tmr-

#include <armor.h>
#include <ansi.h>
inherit SHIELD;

int update_shield(object me,int sk,int inn);
void destruct_shield(object me);

void create()
{
        set_name(CYN"���Z�Ѭ�"NOR,({"god shield","shield","god-benison-shield" }) );
        set("long","�����u���ѤW���A�H�����o�X�^���C\n");
        set_weight(1);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
        set("unit", "��" );
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

        //�]�w���z���m�O
        ob->set("armor_prop/armor", i ); 
        //�]�w�k�N���m�O
        if(sk>50) 
               ob->set("armor_prop/shield", i );
//���[�ݩ�
       if( sk>80 && random(100) > 70 )
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
        message_vision("$N�⤤�����Z�ޤƦ��@�}�����A���������F�C\n",me);
        destruct(this_object() );
        return; 
}


