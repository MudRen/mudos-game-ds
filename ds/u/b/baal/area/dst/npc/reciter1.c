#include <ansi.h>
inherit NPC;

void create()
{
        set_name("�u�|��",({"reciter"}) );
        set("long","
�t���w�𪺧u�|��, �L�̪��u�@�N�O�I�|���w�����y, ���ҵo�@�H����
�z�ҧV�O, �`�`�����X�̱q�L�̪��|�g�n���o��ҥ�, �L�̪��u�@�n��
�������۹�ѯ���§�g.\n"
        );
        set("age",21);
        set("level",7);
        set("int",12);
        set("race","�H��");
        set("attitude", "peaceful");
        set("unarmed",15);    //�Φbmob�W��...
        set("dagger",15);    //�Φbmob�W��...
        set("chat_chance",15);
        set("chat_msg",({
        "�u�G�̧��y�����u�w�D�G�u�s���j�j�n�� ~~�v�C\n",
        "�u�G�̧��y�����u�w�D�G�u���Ъ������C�Y ~~�v�C\n",
        "�u�G�̧��y�����u�w�D�G�u�ѪL�|�H������ ~~�v�C\n",
        (:command("think"):),
        (:command("ponder �u�U�@�y�ѤF...�v"):),
        "�u�G�̧��y�����u�w�D�G�u�Q���ܶ½G���Ծ� ~~�v�C\n",
        "�u�G�̧��y�����u�w�D�G�u���y�j�j�����M ~~�v�C\n",
        "�u�G�̧��y�����u�w�D�G�u���j�j�Ѧ��] ~~�v�C\n",
        "�u�G�̧��y�����u�w�D�G�u�p�ͦn�i�R ~~�v�C\n",
        "�u�G�������ݵۤѪ�, �@�۪��D�G�u�^�S��^��, �^���ۤߪ��g���A�����w, �P�±z�礩�o�@���_�Q�����ѡv�C\n",
        }) );
        setup();                
        carry_object(__DIR__"wp/dagger.c")->wield();
        add_money("coin",50);
}

void die()
{
  int i;
        object ob;
        if( !ob = query_temp("last_damage_from") )
        ob = this_player(1);
        LOGIN_D->set_reboot(0);
        if( !ob ) 
        {
                ::die();
                return;
        }
  i=ob->query_temp("DST/hatred");
  if(ob->query_temp("DST/hatred")==0)
  {
        message_vision(HIW"�u�|�̲Y�F���G�s�n�ǤF�X�h...\n"NOR,ob);
        message_vision(HIY"�t���w��𳻪�����F���F�P�ɦy�n�R�q�G�u�t���w��D��"HIR""+ob->name(1)+""HIY"���J�I�I�I�v\n"NOR,ob);
        message_vision(HIR"���z�����^�S��(God of Wisdom-Intser)���㪺�n���ۤѤW�ǨӡG�����k�v�B���������M�h�̡A
�l��"+ob->name(1)+"���L���F��D���g�@�I�I\n"NOR,ob);
  }
  ob->set_temp("DST/hatred",i+1);
        ::die();
        //destruct(this_object());
        return;

}

