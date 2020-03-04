#include <ansi.h>
inherit NPC;

void create()
{
        set_name(HIG "�s��" NOR,({"dragon tiger","tiger", "dragon"}) );
      set("title",HIM "���u���~" NOR);
        set("long",@LONG
�s��O�ۦW�����u���~�A��ӷ��󯳺~�|�F�����s��R���C
�D�ѱ`�⥦�̴y�z������Ϊ��}�O�C�p�m�ӤW�n�u�T�B�F��
�g�n���G�u���s�B�̡A��]�C��̡A�D�]�C�����s�B�A�Ҩ�
����A�P�D�X�u�A���Ͷ��]�C�s�B�̡A�^�D���h���C�}�Ѻ�
�a�A�@�����]��Ǵc��������A�C�h�s�t���e�{���A��B��
�����N�Ӵ²{���C�����s�B�̡A�������A�����l�C�Τ��T��
�A���ۭ����A�Өө����p���ʱѸ����šC�E�h���ΡA���h
�����A�P�Ѧa�������V�X���@�@�F�]�C�v
LONG    
        );
        set("race", "beast");    
        set("unit","��");
        set("age", 600);
        set("level", 45);
        set("attitude", "heroism");    
        set("limbs", ({ "�Y��", "����","�ݳ�","����","�s��","�I��" }) ); 
        set("verbs", ({ "bite","claw" }) );
        add("addition_hp", 5000);
        add("addition_armor", 90);
        add("addition_damage", 80);
        setup();
        set_temp("apply/armor",100);
        set_temp("apply/shield",100);
        set_temp("apply/damage",50);
          if(random(10)<8) carry_object(__DIR__"eq/dragon-tiger-armor")->wear();
        else carry_object(__DIR__"eq/dragon-tiger-armor2")->wear();
        carry_object(__DIR__"obj/dragon-tiger-pill");
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

        message("world:world1:vision",
                HIG"\n�i�D�������j" + HIM "�H���D�[���u���~�u�s��v�Q"+ob->name(1)+HIM "����F�C\n"+NOR, users());
        ob->add("popularity", 2); //�n��
        ::die();
        return;
}

