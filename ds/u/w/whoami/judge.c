#include <localtime.h>
#include <login.h>
#include <ansi.h>
inherit NPC;

string *order =
({
        ""HIY"", ""HIG"", ""HIR"", ""HIC"", ""HIW"", ""HIM"", ""HIB""
});
string *key =
({
"�ݡ������ݡ��ݡ������ݡ������ݡ��ݡ��ݡ������ݡ������ݡ������ݡ������ݡ�����",
"�����ߡ����������ߡ������ߡ������������������������������ߡ������ߡ������ߡ�",
"�������������ݡ������ݡ������������������������������@�@��������������������",
"�������������������������ߡ������{�������ߡ������ߡ��@�@���������ߡ������ߡ�",
"���������������������ݡ������@�@�����ݡ��������������@�@�������������ݡ�����",
"����������������������������@�@��������������������@�@��������������������",
"�z�������z���z�������z�������z���z���z�������z�������z�������z�������z������",
"�x���{���x���|�w�{���|�w�{���x���x���x���w�}�x���w�}�|�w�{���x���{���x���{��",
"�x���x���x���z�������z�������x�������x�������x�������@�@�x���x�������x������",
"�x���x���x���x���w�}�|�w�{���|�w�{���|�w�{���x���{���@�@�x���x���{���|�w�{��",
"�x�������x���x�������z�������@�@�x���z�������x�������@�@�x���x�������z������",
"�|�w�w�}�|�}�|�w�w�}�|�w�w�}�@�@�|�}�|�w�w�}�|�w�w�}�@�@�|�}�|�w�w�}�|�w�w�}",
"�������ߡ��ߡ������ߡ������ߡ��ߡ��ߡ������ߡ������ߡ������ߡ������ߡ�������",
"���ݡ��������������������������������������塴�����������������ݡ������ݡ���",
"�������������������������������������������ߡ������ߡ@  ��������������������",
"�����������������������������������������������ݡ����@  �������ݡ�����������",
"�������������������{���������@�@���������������������@  ��������������������",
"����������������������������@�@��������������������@�@��������������������",
"�������{���{�������{�������{���{���{�������{�������{�������{�������{�������{",
"���z���x���x�|�w���x�|�w���x���x���x���z�w�}���z�w�}�|�w���x���z���x���z���x",
"���x���x���x�������x�������x�������x�������{�������{�@�@���x�������x�������x",
"���x���x���x���z�w�}�|�w���x�|�w���x�|�w���x���z���x�@�@���x���z���x�|�w���x",
"�������x���x�������{�������x�@�@���x�������x�������x�@�@���x�������x�������x",
"�|�w�w�}�|�}�|�w�w�}�|�w�w�}�@�@�|�}�|�w�w�}�|�w�w�}�@�@�|�}�|�w�w�}�|�w�w�}",
"����������������������������������������������������������������������������",
"�������������㡴�����㡴�����������������������������㡴��������������������",
"�����ߡ������������������塴������������������������    ���������塴�����塴",
"���������������������㡴�����㡴�����㡴�������������@�@�������������㡴����",
"�������������������������塴    ���������塴�����塴�@�@���������塴��������",
"�㡴�����㡴�㡴�����㡴�����@�@�㡴�㡴�����㡴�����@�@�㡴�㡴�����㡴����",
"�z�w�w�{�z�{�z�w�w�{�z�w�w�{�z�{�z�{�z�w�w�{�z�w�w�{�z�w�w�{�z�w�w�{�z�w�w�{",
"�x�������x���|�������|�������x���x���x�������x�������|�������x�������x������",
"�x���x���x���z�w�w���z�w�}���x���}���x���w�{�x���w�{�@�@�x���x���}���x���}��",
"�x���x���x���x�������|�������|�������|�������x�������@�@�x���x�������|������",
"�x���}���x���x���w�{�z�w�}���@�@�x���z�w�}���x���}���@�@�x���x���}���z�w�w��",
"�|�������|���|�������|�������@�@�|���|�������|�������@�@�|���|�������|������",
"����������������������������������������������������������������������������",
"�������������������������������������������塴�����塴����������������������",
"�������������������������������㡴���������ߡ������ߡ@�@�������㡴�����㡴��",
"�������������������塴�������������������������������@�@��������������������",
"���㡴�����������������������@�@���������������㡴���@�@�������㡴����������",
"�������塴�塴�����塴������@�@���塴�����塴������@�@���塴�����塴������",
"�z�w�w�{�z�{�z�w�w�{�z�w�w�{�z�{�z�{�z�w�w�{�z�w�w�{�z�w�w�{�z�w�w�{�z�w�w�{",
"�������x���x�������x�������x���x���x�������}�������}�������x�������x�������x",
"���x���x���x�z�w���x�z�w���x���|���x���|�w�{���|�w�{�@�@���x���|���x���|���x",
"���x���x���x�������}�������x�������x�������x�������x�@�@���x�������x�������x",
"���|���x���x���w�w�{�z�w���x�@�@���x�z�w���x���|���x�@�@���x���|���x�z�w���x",
"�������}���}�������}�������}�@�@���}�������}�������}�@�@���}�������}�������}",
"����������������������������������������������������������������������������",
"����������������������������������������������������������������������������",
"���������������������������������������������������ߡ@�@��������������������",
"�����������������������������������������������������@�@��������������������",
"�����������������������������@�@���������������������@�@��������������������",
"����������������������������@�@��������������������@�@��������������������",
"�z�w�w�{�z�{�z�w�w�{�z�w�w�{�z�{�z�{�z�w�w�{�z�w�w�{�z�w�w�{�z�w�w�{�z�w�w�{",
"�x�z�{�x�x�x�|�w�{�x�|�w�{�x�x�x�x�x�x�z�w�}�x�z�w�}�|�w�{�x�x�z�{�x�x�z�{�x",
"�x�x�x�x�x�x�z�w�}�x�z�w�}�x�x�|�}�x�x�|�w�{�x�|�w�{�@�@�x�x�x�|�}�x�x�|�}�x",
"�x�x�x�x�x�x�x�z�w�}�|�w�{�x�|�w�{�x�|�w�{�x�x�z�{�x�@�@�x�x�x�z�{�x�|�w�{�x",
"�x�|�}�x�x�x�x�|�w�{�z�w�}�x�@�@�x�x�z�w�}�x�x�|�}�x�@�@�x�x�x�|�}�x�z�w�}�x",
"�|�w�w�}�|�}�|�w�w�}�|�w�w�}�@�@�|�}�|�w�w�}�|�w�w�}�@�@�|�}�|�w�w�}�|�w�w�}",
});
string str = "\n\n";
string answer = "";
int in_ask;
void create()
{
        set_name("�B�P�x", ({"ice judge", "judge"}));
        set("long", "�@��f�d���a���f�P�x�A�A��������(answer)�L�T�Ӱ��D�~������L���]�x�C\n");
        set("gender", "�k��");
        set("age", 40);
        set("no_kill", 1);
        set("can_kick_out", 1);
        set("hero",1);
        setup();
        in_ask = 0;
}
/*
void greeting(object ob)
{
        int date = time();

        if(!ob || environment(ob) != environment()) return;
        if(localtime(date)[LT_HOUR] < 12)
        {
                command("say �o�Ӯɬq�ڤ����Ӧb�o�·ЦU�쪺�I\n");
                message_vision("$N�Ƭ��@�ΥշϡA�����b�Ť��C\n", this_object());
                destruct(this_object());
        } 
}
*/
void init()
{
        int guess, time;
        string id;
        ::init();

        id = this_player()->query("id");
        if(!query_heart_beat(this_object()))
                set_heart_beat(1);
        add_action("do_answer", "answer");
        this_player()->delete_temp("answer/right");
        if(guess = this_player()->query("answer/guess"))
        {
                if(guess > 12) guess = 12;
                this_player()->set_temp("answer/wrong", guess);
        }
        else this_player()->set_temp("answer/wrong", 3);
        time = this_player()->query_temp("answer/wrong");
        this_player()->delete_busy();
        call_out("judge", 1);
        message_vision("�B�P�x���D�G �u"HIG+this_player()->name()+HIY"�v��������"HIC+chinese_number(time)+"�D"HIY"�A��i���}���a�I\n"NOR);
}
int do_answer(string arg)
{
        string s, myid, myname, id, home_path;
        object me, *inv, ob, who;
        int answ, ans, i, time;
        who = this_player();
        myid = who->query("id");
        myname = who->name();
        me = this_object();

        if(!arg)
                return notify_fail("�B�P�x���D�G�ЧA�^���@�ӼƦr�C\n");
        if(who->query_temp("answer/right") >= 1)
                return notify_fail("�B�P�x���D�G�A�o�D�w�g����F�A�е��U�@�D�C\n");
        if(!in_ask)
                return notify_fail("�B�P�x���D�G�A�������U�@�D�C\n");
        if(arg == answer)
        {
                who->add_temp("answer/wrong", -1);
                who->set_temp("answer/right", 1);
                time = who->query_temp("answer/wrong");
                str = "\n\n";
                message_vision("�B�P�x���D�G �u"HIC+ myname +HIY"�v����F�o�@�D�A�٦�"HIR+chinese_number(time)+"�D"HIY"�����^���I\n"NOR,me);
                if(time <= 0)
                {
                        who->delete("answer");
                        if(who->query("be_jail") == 1)
                        {
                                message_vision("�B�P�x���D�G �ܡI��ӡu"HIR+myname+HIY"�v�Q�k���H�Ѥl�o�N�e�A�^�h�A�D�I\n"NOR,me);
                                who->move("/open/always/ppl_jail");
                                who->set("valid_startroom","/open/always/ppl_jail"); 
                        }
                        else
                        {
                                message_vision("�B�P�x���D�G �ܦn...�u"HIC+ myname +HIY"�v�A�A�ݰ_�Ӥ����³J�A�A�i�H�^�a�F�C\n"NOR,me);
                                who->delete_temp("answer"); 
                                if(stringp(s = who->query_temp("valid_startroom")))
                                {
                                        who->set("valid_startroom", "/open/world1/tmr/area/hotel
");
                                        who->delete_temp("robot_check");
                                        if(file_size(home_path = user_path(geteuid(who)) + "workroom.c") > 0)
                                                who->move(home_path);
                                }
                                else
                                {
                                        who->set("valid_startroom", "/open/world1/tmr/area/hotel");
                                        
                                }
                        }
                }
        }
        else
        {
                who->add_temp("answer/times", 1);
                who->add_temp("answer/guess", 1);
                time = who->query_temp("answer/wrong");
                if(time < 12)
                {
                        switch(who->query_temp("answer/guess"))
                        {
                                case 0..2 :
                                        message_vision("�B�P�x���D�G �u"HIG+ myname +HIY"�v�����F�A�зQ�M���A�^���I\n"NOR,me);
                                break;
                                case 3 :
                                        message_vision("�B�P�x���D�G �u"HIG+ myname +HIY"�v�w�g�����T�D�F�A�n�}�l�ֿn���~�D�ƤF��I\n"NOR,me);
                                break;
                                case 4..12 :
                                        who->add_temp("answer/wrong", 1);
                                        message_vision("�B�P�x���D�G �u"HIG+ myname +HIY"�v�����F�A��"HIR+chinese_number(who->query_temp("answer/wrong"))+"�D"HIY"�����^���I\n"NOR,me);
                                break;
                        }
                }
                else
                {
                        message_vision("�B�P�x���D�G �u"HIG+ myname +HIY"�v�����F�I�A�٦�"HIR+chinese_number(who->query_temp("answer/wrong"))+"�D"HIY"�����^���I\n"NOR,me);
                }
                if(who->query_temp("answer/guess") >= 8)
                {
                        message_vision("�B�P�x���D�G �u"HIM+ myname +HIY"�v�A�A�A���ڶòq�ڡA�u�a�A�I\n"NOR,me);
                        who->delete("env/immortal");
                        if(time > 12) time = 12;
                        who->set("answer/guess", time);
time = 259200;
time += time();
                        ob->set("winter_time", time);
                         if(ob->query("be_jail"))
                            {
                             message_vision("�B�P�x���D�G �u"HIR+ myname +HIY"�v�A�A�A�o�b�ڡI�A��w�ڡI���ںu�^Ţ�l�̡I�I\n"NOR,me);
                             ob->set("valid_startroom","/open/always/ppl_jail");
                             ob->move("/open/always/ppl_jail");
                            } else {
                                    ob->set("valid_startroom","/u/w/whoami/newjudgeroom");
                                    ob->save();
                                    command("quit "+ob->query("id"));
                       }
                }
        }
        return 1;
}
void judge()
{
        string clr, color;
        int x, len, temp, line, ltemp, c, cl, a;
        object *inv, me = this_object();

        x = random(7);
        switch(x)
        {
                case 0 : clr = "y"; break;
                case 1 : clr = "g"; break;
                case 2 : clr = "r"; break;
                case 3 : clr = "c"; break;
                case 4 : clr = "w"; break;
                case 5 : clr = "m"; break;
                case 6 : clr = "b"; break;
        }
        remove_call_out("judge");
        remove_call_out("say_answer");
        if(in_ask) message_vision("�B�P�x���D�G ���H�ӤF�A�ڭ̭��s�X�D�a�I\n",me);
        inv = all_inventory(environment(this_object()));
        answer = "";
        str = "\n\t";
        temp = len = random(3) + 3;
        while(temp--)
        {
                answer += "0";
                answer[<1] += random(10);
        }
        line = random(10)*6;
        message_vision("�B�P�x���D�G �аݥH�U���Ʀr���h�֡H�Цb�Q�������@��(answer �Ʀr+�C��)�C",me);
        for(a = 0; a < sizeof(inv); a++)
        {
                if(userp(inv[a]))
                {
                        inv[a]->delete_temp("answer/right");
                        inv[a]->delete_temp("answer/times");
                        if(inv[a]->query("env/color") == "YES")
                        {
                                color = "\n    �i "HIG"�i"NOR"�Gg  "HIY"�i"NOR"�Gy  "HIR"�i"NOR"�Gr  "HIM"�i"NOR"�Gm  "HIW"�i"NOR"�Gw  "HIC"�i"NOR"�Gc  "HIB"�i"NOR"�Gb �j\n";
                        }
                        else color = "";
                }
        }
        for(ltemp = line; ltemp < line+6; ltemp++)
        {
                for(temp = 0; temp < len; temp++)
                {
                        c = answer[temp] - '0';
                        if (c != 1) cl = 7;
                        else cl = 3;
                        if (c > 1) c = c * 8 - 4;
                        else c *= 8;
                        cl += c;
                        str += key[ltemp][c..cl];
                }
                str += "\n\t";
        }
        answer += clr;
        message_vision("�B�P�x���D�G \n" + order[x] + str + NOR + color,me);
        in_ask = 1;
        call_out("say_answer", 15);
}
void say_answer()
{
        int i, time;
        object *inv, ob, me = this_object();
        string id, name;
        in_ask = 0;

        if(environment())
        {
                inv = all_inventory(environment());
                for(i = 0; i < sizeof(inv); i++)
                {
                        ob = inv[i];
                        id = ob->query("id");
                        name = ob->name();
                        if(!userp(ob) && ob != me)
                        {
                                destruct(ob);
                                continue;
                        }
                        // ����N�����ˬd�F
                        if(ob->query_temp("answer/right"))
                        {
                                ob->delete_temp("answer/right");
                                continue;
                        }
                        // �ѤU���N�O������
                        tell_object (ob, HIY"�B�P�x���D�G��I�o�D���T���׬O�u"HIW+ answer +HIY"�v�I\n"NOR);
                        if(userp(ob) && !wizardp(ob))
                        {
                                message_vision("�B�P�x���D�G �u"HIM+ name +HIY"�v�A�A�����ӺC�F��I���ڤp�ߤ@�I�I�I\n"NOR,me);
                                ob->add_temp("answer/slow", 1);
                                if(ob->query_temp("answer/slow") > 8)
                                {
                                        message_vision("�B�P�x���D�G �u"HIR+ name +HIY"�v�A�A�A�o�b�ڡI�A��w�ڡI���ڥh���a�I�I\n"NOR,me);
                                        time = ob->query_temp("answer/wrong");
                                        ob->delete("env/immortal");
                                        if(time > 12) time = 12;
                                        ob->set("answer/guess", time);
                        ob->set("winter_time", time);
                         if(ob->query("be_jail"))
                            {
                             message_vision("�B�P�x���D�G �u"HIR+ name +HIY"�v�A�A�A�o�b�ڡI�A��w�ڡI���ںu�^Ţ�l�̡I�I\n"NOR,me);
                             ob->set("valid_startroom","/open/always/ppl_jail");
                             ob->move("/open/always/ppl_jail");
                            } else {
                                    ob->set("valid_startroom","/u/w/whoami/newjudgeroom");
                                    ob->save();
                                    command("quit "+ob->query("id"));
                                   }
                                }
                        }
                }
        }
        inv = all_inventory(environment());
        if(sizeof(inv)) call_out("judge", 1);
}


