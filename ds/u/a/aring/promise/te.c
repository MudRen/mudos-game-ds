#include <ansi.h>
#include <path.h>

inherit NPC;

void create()
{
        set_name("�ڤۯ몺�s��ɮv", ({"smaster"}) );
    set("gender", "�k��");
    set("combat_exp", 100000);
    set("long",
    "�L�O�Ѧ�s�⪺���ɱЮv�A���Ѱ򥻪��ޥ��V�m�C�A�i�H\n"
    "�ϥ�"HIY"slist"NOR"�Ӭݬݦ�����ޥ��i�H���Ѿǲ�(train)�C�]�i\n"
    "�H��advance <level���ݩ�> �Ӥɯ�, �ɯūe��ĳ���ϥ�\n"
    "level ���O�Ӭd�\\�һݭn���g��ȡC\n"
    );
        set("no_join", 1);
        set("level", 200);
        set("age", 50);
    set_skill("unarmed", 100);
        set_skill("dodge", 100);
        set_skill("parry", 100);
 setup();
         }
void die()
{
    object ob,scr;
        if( !ob = query_temp("last_damage_from") )
        ob = this_player(1);
        if( !ob )
        {
                ::die();
                return;
        }
        
        message("world:world1:vision",
HIC"�ڤۯ몺�s��ɮv�A�Q�q�q�L�W"HIW"�i"+ob->name(1)+"�j"HIC"�����F�C\n"+NOR
        ,users());
          ob->add("popularity",5);

                 tell_object(ob,HIG "(�A���n��W�[���I�F�C)\n" NOR );

        ::die();
        return;
}

