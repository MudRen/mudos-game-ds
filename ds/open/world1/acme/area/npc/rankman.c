#include <ansi.h>
inherit NPC;
void create()
{
        set_name("���L����" , ({ "give me rank","rank" }) );
        set("long",@long
�L�O���ѯ��Z�ШS��==Rank ��T==���H�A�S��rank��L�n
�N��F,��L���ܩγ\��i�@�B�o������C
long
);
        create_family( "���Z��",3,"�Ю{");
        set("level",10);
        set("race","�H��");
        set("age",20);
        set("nickname","�t�z����");
        set("adv_class",1);
        set("class1","���Z��");
        set("no_fight",1);
        set("gender","�k��");
        set("talk_reply","�Y�A�O���Z�СA�ӥB�Q�nRANK�N->say �ڭnRANK��");
        setup();
}
void init()
{
        add_action("do_say","say");
}
int do_say(string arg)
{
    int lv;
    string rank;
    object me;
    me=this_player();
    if(arg == "�ڭnRANK��" && me->query("class1") == "���Z��" )
    {
        command("say �n�n�I�I�����A���I");
        lv = me->query("level");
        lv = lv/10;     // �N rank �������Ӽh��
        if( me->query("gender") == "�k��" )
        {
                switch( lv )
                {
                        case 0: rank = "���Z�вĤT�N�Ю{"; break;
                        case 2: rank = "���Z�Ф��P�K�}��"; break;
                        case 3: rank = "���Z�Ф����C����"; break;
                        case 4: rank = "���Z�Ф����k�C�L"; break;
                        default: rank = HIC"���Z�Ф����ѷ��a"NOR;
                }
        }
        else
        {
                switch( lv )
                {
                        case 0: rank = "���Z�вĤT�N�Ю{"; break;
                        case 1: rank = "���Z�вĤT�N�Ю{"; break;
                        case 2: rank = "���Z�Ф��P�K�}��"; break;
                        case 3: rank = "���Z�Ф����C����"; break;
                        case 4: rank = "���Z�Ф������C�L"; break;
                        default: rank = HIC"���Z�Ф����ѷ��a"NOR;
                }
        }
        me->set("guild_rank",rank);
     }

}
