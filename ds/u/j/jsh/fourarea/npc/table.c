#include <ansi.h>
inherit ITEM;
        
void create()
{
        set_name("����", ({"beg table","table"}) );
        set("long",@LONG
�o�ಽ�¬ݦ��w���ܪ������v�A�B�]���ܪ����ɶ��S���ϥΡA�b����
���᭱�٦��@�y�o�󪺤��l�A�w�S���b�I�����A���O���¤W�o������
�����A�O�_�n�Ψ�Y�ت��~�A�~��Ѷ}���������� ? (screw xxx)

LONG
        );
        set_weight(1000);
        set_max_capacity(10);
        set_max_encumbrance(500000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("no_get",1);
        set("no_drop",1); 
        set("no_sac",1);      
        set("unit", "��");
        set("volume",5000);
        set("value",123);
        }
        setup(); 
}

void init()
{
        add_action("kok_blood","kok");
        add_action("screw_fire_dragon_liver","screw");
}

int screw_fire_dragon_liver(string str)
{
        object me=this_player();
        object ob;

        if(str=="fire-dragon liver")
        {
        if(!ob=present("fire-dragon liver",me))
                {return notify_fail("�A�n������F�裫 ???\n");}

        if(this_object()->query_temp("fire-dragon liver")==1)
                {
                write("���L�F .. .  .. .\n");
                return 1;
                }
                destruct(ob);
                message_vision(
                HIW"$N�N���s�x�ΤO�@���A�A���⪺���s��A�ɤJ��î�A�w�w�W���¡C\n"NOR,me);
                set_temp("fire-dragon liver",1);
                return 1;
        }

}

int kok_blood(string str)
{
        if(this_object()->query_temp("opened") != 0) return 0;
        
        if(str=="blood" || str=="��")
        {
        object me,b;
        me=this_player();

        message_vision(
        HIR"\n$N�ΤO���祴�w�b���¤W�����s�x��I\n"NOR,me);

         if(this_object()->query_temp("fire-dragon liver")==1)        
         {
          message_vision(
          HIB"���M�@�}"HIR"�� �]"HIB"�q���l��«�X�A�I�����}�B�n�C��ӥX . . . . \n"NOR,me);

          b=new(__DIR__"fire.c" );
          b->move(environment(this_object()) );
          delete_temp("fire-dragon liver");
          //set_temp("opened",1);
          return 1;
          }
        else
          {
          message_vision(
          HIG"$N���@�ӧb�l�@��...�����D�b�F���C\n"NOR,me);
          }
        return 1;
        }
}

