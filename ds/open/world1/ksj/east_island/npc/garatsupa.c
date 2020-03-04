#include <ansi.h>
inherit NPC;

void create()
{
  set_name(HIG"�e��"NOR, ({"garatsupa"}) );
  set("long",@LONG
�����j���O�|�Τ����ൣ�몺���סA�㦳�N�@�ǰ������ͥͦa��J��
�����O�q�C�Y�W���۽L�l�A�I����۹��t�߯몺�F��A�ӥB����i�H
���Y�ۦp�C���Y�W���L�l�˺��ۤ��A�Y�O�L�l���������\���ܡA�N�|
���W�ॢ�O�q���ܱo��z�C�e���ðΩ�e�t����A���w���˧O�H�A��
�R����L���H���ۼ��C
LONG
);
  set("race", "beast");
  set("unit","��");
  set("age",60);
  set("gender", "����" );
  set("level",30);
  set_skill("unarmed",60);
  set_skill("dodge",40);
  set_skill("parry",30);
  set("limbs", ({ "�Y��", "����","����","�k��","���}","�k�}"}) );
  set("verbs", ({"bite","claw","crash"}) );
  setup();
  carry_object(__DIR__"eq/turtle-shell-armor")->wear();
  carry_object(__DIR__"eq/stone-shield")->wear();
}

void init()
{
        add_action("do_hit","hit");
 
}

int do_hit(string str)
{
        object me,ob;
        me=this_object();
        ob=this_player();
 
        if(!str || str!="garatsupa") return 0;
        if( me->is_fighting(ob) ) return notify_fail("�A���b�԰����A�S�Ű��o��ơC");
        if( random(10)<2 && ob->query_temp("weapon"))
        {
         message_vision(
         HIC"\n$N�X�䤣�N�A���ʤ⤤�L�����e���Y�W���L�l�V�h�I\n"NOR
         HIG"\n�e�����p�߳Q$N�����A�y���Y������A���b�a�W�C\n"NOR,ob);
         me->start_busy(20);
        }
        else
        {
         message_vision(
         HIC"\n$N�X�䤣�N�A���ʤ⤤�L�����e���Y�W���L�l�V�h�I\n"NOR
         HIR"\n�e���W�W�i�i�a���@�ǰ{�F�}�h�I\n"NOR,me);
         me->fight_ob(ob);
         ob->add_busy(1);
        }
        return 1;
}

void die()
 {
        object ob;
        if( !ob = query_temp("last_damage_from") )
        ob = this_player(1);
        if( !ob ) 
        {
                ::die();
                return;
        }
 
        switch( random(100) ) {
        case  0..2: new(__DIR__"eq/garatsupa-necklace")->move(this_object());
        break;}
        ::die();
        return;
 }
