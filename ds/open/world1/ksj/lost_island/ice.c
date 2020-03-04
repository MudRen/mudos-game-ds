#include <ansi.h>
#include <path.h>
inherit ITEM;

void create()
{
        set_name(HIC"���B"NOR, ({"ice"}) );
        set("long",@LONG
�@�ӥ��j���B���A���y�p�s�����A�̭����@�Ӭݤ��M�����j����
�A�B���H�����w�C���t�׿ĤơA�γ\�i�H�x(labber)�I�F��Ĥƥ��C
LONG
        );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("no_get",1);
        set("no_drop",1);
        set("unit", "��");
        set("volume",1000);
        set("value",500);
        }
        setup(); 
}

void init()
{
        add_action("do_labber","labber");
 
}

int do_labber(string str)
{
        object me,b,z,ob;
        me=this_player();
 
        if(!str || str!="blood") return 0;
        if(!objectp(z=present("shell dragon blood",me) ) )
        return notify_fail("�A�S���F��i�H�x�� ? \n");

        // 1/13 �s�W by ksj
        ob=find_living("_NPC_SWORD_TIGER_");
        if( objectp(ob) )
        {
          if(!environment(ob) )
          {
            destruct(ob);
          }
          else
          {
            message_vision("$N�N����G����x��B�W�A�ĤƦ��@�a������C\n",me);
            destruct(z);
            return 1;
          }
        }
         
        destruct(z);
        message_vision(
        HIW"\n$N�N����G����x��B�W�A�B���H�Y�_�X�]���t�ĤơC\n"NOR
        HIC"\n��M���B���}�A�@�ӥ��j�����v�X�{�b�A���e�I\n"NOR,me);
        message("world:world1:vision",
        HIR"\n\t�q"HIG" ��@�q "HIR"�ǨӥO���~�������宣���q�s�n�I�I\n\n"NOR
        ,users());
        b=new(__DIR__"npc/sword-tiger" );
        b->move(environment(this_object()));
        destruct(this_object());
        return 1;
}
