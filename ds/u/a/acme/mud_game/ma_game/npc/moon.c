#include <ansi.h>
#define TREE "/u/a/acme/mud_game/ma_game/npc/obj/laurel.c"
#include <path.h>
inherit SELLMAN;
inherit NPC;
inherit F_SAVE;
string *place=({"/open/world1/tmr/area/street4.c","/open/world1/cominging/area/bnorth.c","/open/world1/acme/area/st.c"});

mapping game_record;
mapping game_no;

void check_game();
void create()
{
        restore();
        this_object()->delete("short");
        set_name(HIM"�߮Z"NOR, ({ "the goddess of the moon","goddess","moon"}));
        set("long", "�L�O��b��G�W�Y�����P�A���o�Q���нo�A\n"
                    "�B�`�`�a�ۯ��e�A�b�C�~������`�A�����\n"
                    "����L���ܼv�@�C�i�Hñ�W(sign)����~�C\n");
        set("level",1);
        set("gender", "�k��");
        set("race", "�H��");
        set("age", 20);
        set("evil",-20);
        set("attitude", "peaceful");
        set("no_fight",1);
        set("chat_chance", 50);
        set("chat_msg", ({
                (: check_game() :),
        }));
        set("sell_list",([
                "/open/world1/acme/area/npc/obj/pomelo" : 10,
                "/open/world1/acme/area/npc/obj/cake1" : 10,
                "/open/world1/acme/area/npc/obj/cake2" : 10,
                "/open/world1/acme/area/npc/obj/cake3" : 10,
                "/u/a/acme/mud_game/ma_game/npc/obj/mortar.c" : 1,
                 "/u/a/acme/mud_game/ma_game/npc/obj/pestle.c" : 1,
        ]) );
    set_temp("sign",1);
        setup();

        set_living_name("mud_game");
}
string query_save_file() { return DATA_DIR + "game/ma_game"; }

void check_game()
{
        int i;
        string month,time,day,msg="";
        object tree;

        time = ctime(time());
        month = time[4..6];
        day = time[8..9];
      return 0; // ���ʵ��� tmr 2006/10/16
        switch( month )
        {
                case "Sep":     //�E��
                        if( objectp(tree=find_living("ma_game")) )
                        {
                                if(!environment(tree)) destruct(tree);
                                return;
                        }
                        msg += HIM"\n\t�߮Z�իռ۹D�G\n\n"NOR;
                        msg += HIG"\t\t�Q�����v��x��A���i���H�W�V���C\n";
                        msg += "\t\t�������Z�L����A���ʲM�N�۪�t�C\n\n"NOR;
                        msg+="\t(�A�o�{�Ѫų\\�h�ƪ��Y����a���C)\n";
                        message("system",msg,users());

                        i=sizeof(place);
                        while( i-- )
                        {
                                tree=new(TREE);
                                tree->move(place[i]);
                        }
                        break;
                case "Oct":     //�Q��
//                          if( day==" 1" )
                        {
                                if( objectp(tree=find_living("ma_game")) )
                                {
                                        if(!environment(tree)) destruct(tree);
                                        return;
                                }
                                msg += HIM"\n\t�߮Z�իռ۹D�G\n\n"NOR;
                                msg += HIG"\t\t�Q�����v��x��A���i���H�W�V���C\n";
                                msg += "\t\t�������Z�L����A���ʲM�N�۪�t�C\n\n"NOR;
                                msg+="\t(�A�o�{�Ѫų\\�h�ƪ��Y����a���C)\n";
                                message("system",msg,users());

                                i=sizeof(place);
                                while( i-- )
                                {
                                        tree=new(TREE);
                                        tree->move(place[i]);
                                }
                        }
                          if( !this_object()->query_temp("sign") )
                        {
                                msg += HIM"\n\t�߮Z�իռ۹D�G\n\n"NOR;
                                msg += HIG"\t\t����ʵ����A�Щ�|�餺������~�C\n\n"NOR;
                                message("system",msg,users());
                                this_object()->set_temp("sign",1);
                        }
                        break;
        }
        return;
}

void init()
{
         add_action("do_sign","sign");
        add_action("do_list","list");
        add_action("do_buy","buy");
        {
                object ob;
                ::init();
                if( interactive(ob = this_player()) && !is_fighting() )
                {
                        remove_call_out("greeting");
                        call_out("greeting", 1, ob);
                }
        }
}

void greeting(object ob)
{
        string msg="";
        if( !ob || environment(ob) != environment() ) return;
        msg = "�o��"+ RANK_D->query_respect(ob) +"�ӶR";
        if( random(2)>0 ) msg += "�Ǥ��Y�Y�a�C";
        else msg+="���c�l�Y�Y�a�C";
        command("say "+ msg );
        return;
}

int do_sign()
{
        string id;
        object me=this_player(),gift;
        id=getuid(me);
        if( !this_object()->query_temp("sign") )
                return notify_fail("���G�ɶ��٨S��A�L�k������~�C\n");
        if( !mapp(game_record) )
                return notify_fail("�ثe�ٵL�k������~�I\n");

    /*
        if( !undefinedp(game_no[id]) )          //���o�W
        {
                write("No."+game_no[id]+"\n");
                switch( game_no[id] )
                {
                        case 1: gift=new("/u/a/acme/mud_game/gift/lv5.c"); break;
                        case 2: gift=new("/u/a/acme/mud_game/gift/lv4.c"); break;
                        case 3: gift=new("/u/a/acme/mud_game/gift/lv3.c"); break;
                        case 4: gift=new("/u/a/acme/mud_game/gift/lv2.c"); break;
                        case 5: gift=new("/u/a/acme/mud_game/gift/lv1.c"); break;
                        default: return notify_fail("�A���W�����G�����D�A�S��k����A�Ч�Ův�B�z�I\n"); break;
                }
                if( gift->move(me) )
                        message_vision("$N�V$n��F�@��"+gift->query("name")+"�C\n",me,this_object());
                else
                {
                        gift->move(environment(me));
                        message_vision("$N�V$n��F�@��"+gift->query("name")+"�A�����b�a�W�F�C\n",me,this_object());
                }
                map_delete(game_no,id);
                this_object()->save();
        }
    */

        if( !undefinedp(game_record[id]) )      //���ѥ[
        {
                  gift=new("/open/world1/tmr/game/2006_moon/ankle");
                if( gift->move(me) )
                        message_vision("$N�V$n��F�@��"+gift->query("name")+"�C\n",me,this_object());
                else
                {
                        gift->move(environment(me));
                        message_vision("$N�V$n��F�@��"+gift->query("name")+"�A�����b�a�W�F�C\n",me,this_object());
                }
                map_delete(game_record,id);
                this_object()->save();
                return 1;
        }
        else return notify_fail("�A�S��k������~�I\n");
        return 1;
}

