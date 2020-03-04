#include <ansi.h>

inherit NPC;
inherit SELLMAN;

string *list = ({
        "/open/world1/promise/six-legging.c",
        "/open/world1/promise/six-ring.c",
        
});
void create()
{
        set_name(HIM"´�k�f�f"NOR, ({"zhi-lu sister", "sister"}));
        set("gender", "�k��" );
        set("age", 17);
        set("long","�û����������A�n��ڶR���J�O���Х�list �M buy�a�A�d�ݼ��~�Х�elist!!\n");
        set("level",1);
        set("attitude", "friendly");
        set("rank_info/respect", HIC"�������֤k"NOR);
        set("sell_list",([
                __DIR__"dove-chocolate" : 50,
                __DIR__"gin-chocolate" : 50,
        ]) );

        set("chat_chance",10);
        set("chat_msg", ({
                (:command,"say �O�`�۳�A�n�R���J�O�Х�list �M buy��....":),
                (:command,"smile":),
        
}));
       
setup();
}
void init()
{       
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("do_list","list");
        add_action("do_buy","buy"); 

        add_action("list_price","elist");        }

void greeting()

{
        command("say �֨ӶR���J�O�����^^");
        return;
}


int list_price()
{
        string msg;

        msg = HIC"���������C�i���H�`��������~�p�U�G\n"NOR+
                HIY"�סססססססס�"HIM"�C�i���H�������"HIY"�סססססססססססס�\n"NOR+
                HIW"\t�j���G�q���M�ݫ����˹��~�A�ӡC\n"NOR+
                HIW"\t�G���G�H��SAVE EQ�A��C\n"NOR+
                HIW"\t�T���G���������������g���\n"+
                HIW"\t�T���G�n�械���I\n"+
                HIW"\t�����G�j����������������\n"+
                HIW"\t�w�����G�H�����J�O�@�]�C\n"NOR+
                HIY"�ססססססססססססססססססססססססססססס�\n"NOR;
        this_player()->start_more(msg);

        return 1;
}

int accept_object(object me,object ob)
{
        object price;
        int lucky;

        lucky = random(80);

        if( ob->query("id") !="bliss ticket" )
                return notify_fail("´�k�f�f: ���ڳo�ӪF��n�F��.....-_-�C\n");

        if( this_object()->is_busy() ) 
                return notify_fail(this_object()->query("name")+"���D:����..�b�I����!\n");

        this_object()->add_temp("waiting", 1);
        if( this_object()->query_temp("waiting") >= 10 )
        {
                this_object()->start_busy(3);

                this_object()->delete_temp("waiting", 1);
        }

        call_out( (:destruct($1):), 1, ob);
            switch(lucky)
                { 
                case 5:
                        new(__DIR__"no1-ticket")->move(me);
                        command("tchat ���ߪ��a"+me->query("name")+"("+me->query("id")+") ���F�j���A�q���M�ݫ����A���A�Фj�a���L���ߤ@�U�a�I");
                        return 1;
                break;
                case 20:
                        price = new(list[random(sizeof(list))]);
                        price->move(me);
                        command("tchat ���ߪ��a"+me->query("name")+"("+me->query("id")+") ���F�G���A�o��SAVE EQ�A��A�Фj�a���L���ߤ@�U�a�I");
                                                        log_file( "static/gamea",sprintf("[%s] %s(%s) get %s[%s]\n",ctime(time()),me->name(1),getuid(me),price->name(1),base_name(price))); 
                        return 1;
                break;
                case 25:
                        me->add("exp", 100000);
                        command("tchat ���ߪ��a"+me->query("name")+"("+me->query("id")+") ���F�T���A�o��100000 exp�A�Фj�a���L���ߤ@�U�a�I");
                        return 1;
                break;

                case 35:
                        me->add("popularity", 10);
                        command("tchat ���ߪ��a"+me->query("name")+"("+me->query("id")+") ���F�|���A��o10�I�n��A�Фj�a���L���ߤ@�U�a�I");

                        return 1;
                break;
                 case 40..50:
                        me->add("bank/past", 30000);
                        command("tchat ���ߪ��a"+me->query("name")+"("+me->query("id")+") ���F�����A��o�j��30000�A�Фj�a���L���ߤ@�U�a�I");
                        return 1;
                break;

                case 60..69:
                        new(__DIR__"dove-chocolate")->move(me);
                        command("say ���ߡA�A���@�ӥ��J�O");
                        return 1;
                break;
                case 70..80:
                        new(__DIR__"gin-chocolate")->move(me);
                        command("say ���ߡA�A���@�ӥ��J�O�C");
                        return 1;
                break;
                default:
                        command("say �u��ѡA���򳣨S���C");
                        return 1;
                break;
        }

        return 1;
}
     

