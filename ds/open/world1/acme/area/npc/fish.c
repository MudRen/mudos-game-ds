#include <ansi.h>
inherit NPC;
void create()
{
        set_name("���H���s",({"man-eating fish","fish"}) );
        set("long","�o�O�@�s���H���A�b�e�L�̤W�U�G�ƪ��F�y���������A�Q���~�H�C\n");
        set("race", "���~");    
        set("unit","�s");
        set("age",2);
        set("level",1);
        set("attitude", "aggressive");
        set("exp",10*random(120));

        set_skill("swim",50+random(20));
        set("limbs", ({ "�Y��", "����", "�e��", "����" }) ); //���𳡦�
        set("verbs", ({ "bite" }) );                         //�����覡
        setup();
}
void die()
{
        int i;
        object ob,obj;
        obj=this_object();
        i=obj->query("die");
        obj->set("die",i+1);
        if( !ob = query_temp("last_damage_from") )
                ob = this_player(1);
        if( !ob ) return;
        if(obj->query("die")>9)
        {
          ::die();
        }
        else {
          message_vision("\n\n  �䤤�@�����H��½�F�L��, �B������W, ���f�F�X�U...�C\n",ob);
          message_vision("\n  ���H�����F�C\n\n",ob);
          obj->set("hp",obj->query("max_hp"));
          obj->set("mp",obj->query("max_mp"));
          obj->set("ap",obj->query("max_ap"));
          obj->set("name",chinese_number(10-obj->query("die"))+"�����H��");
          kill_ob(ob);
        }
}
