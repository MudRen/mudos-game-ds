/* ���� �H����(CRUSH_BONE) ���ʪ� MOB.  by -Acme- */

#include <npc.h>
#include <ansi.h>

inherit F_FIGHTER;
inherit F_SAVE;

int start = -1;

string file_path = "/d/crush_bone/";         // �D����npc��m

/* mob���ɮצ�m */
string *mob_file = ({ "orc_follower.c",
                      "orc.c",
                      "orc_hundred_leader.c",
                      "orc_thousand_leader.c",
                      "orc_commander.c",
                      "orc_herald.c",
                      "orc_envoy.c",
                      "orc_emperor.c"
                   });

/* mob�ҭn���ͪ��ƶq */
int *mob_amount = ({ 15, 15, 20, 25, 20, 10, 5, 1 });

/* mob���ͫ�n���쪺��m */
string *mob_born1 = ({ "map_22_1.c",
                       "map_11_1.c",
                       "map_1_1.c",
                       "map_1_12.c",
                       "map_1_22.c",
                       "map_11_22.c",
                       "map_22_22.c",
                       "map_22_12.c"
                   });

string *mob_born2 = ({ "map_7_9.c",
                       "map_9_16.c",
                       "map_11_9.c",
                       "map_13_16.c",
                       "map_16_14.c",
                       "map_16_10.c",
                       "map_13_7.c",
                       "map_7_7.c"
                   });

/* �n���O�� */
mapping record;

/* ���~�C�� */
mapping gift = ([
                 // �]�k���g��
                 "1" : ([ "name" : "�]�k���g��(55th card)",
                          "need" : 300 ,
                          "file" : "/d/cards/card-55.c", ]),
                 // �x��������
                 "2" : ([ "name" : "�x��������(16th card)",
                          "need" : 100 ,
                          "file" : "/d/cards/card-16.c", ]),
                 // �i�x�s���U�l
                 "3" : ([ "name" : "�h�߸H���U(heartache crush bone bag)",
                          "need" : 100,
                          "file" : "/d/crush_bone/npc/obj/bag.c", ]),
                 // �b�~�H���\
                 "4" : ([ "name" : "�j�~�H���\(Strong-orc tears pill)",
                          "need" : 10,
                          "file" : "/d/obj/orc-tear.c", ]),
                 "5" : ([ "name" : "���������_���U(Seaman's scrotum)",
                          "need" : 20,
                          "file" : "/d/obj/seamanbaby.c", ]),
                   "6" : ([ "name" : "��Y�Y��(94th card)",
                              "need" : 200,
                            "file" : "/d/cards/card-94.c", ]),


               ]);

int do_start();
void do_say();
int do_trigger(string arg);

void create()
{
    set_name( "�Ǵ�" , ({ "jason" }) );
    set("long",@long
    ���۲`��⪺���W�ֽ��A���y��סA�@�I�����c�٪��ˤl�A���O����
�o�M�b�~�H���۷�{�ת��t���C�uť��L�L�̳��ۻy�A�]�����b��ԣ�C
long
);
    set_race("strength");
    set("title", "�j�~�H" );
    set("age", 38);

    if( !restore() ) {
        record = ([]);
        this_object()->save();
    }


    set("chat_chance", 5);
    set("chat_msg", ({
       (: do_start :),
       (: do_say :), 
    }));

    setup();

    set_living_name("_CRUSH_BONE_CONTROLER_");
}

string query_save_file() { return __DIR__"jason"; }

void init()
{
    if( wizhood(this_player()) == "(admin)" ) add_action( "do_trigger", "trigger" );
    if( wizhood(this_player()) == "(admin)" ) add_action( "do_wizset", "wizset" );
    if( wizhood(this_player()) == "(admin)" ) add_action( "do_wizclear", "wizclear" );
    add_action( "do_list", "list" );
    add_action( "do_receive", "receive" );
}

void do_say()
{
    do_chat( ({ "�Ǵ˻��D�G�u����s�b�~�H�A��I��I�@�Ӥ@�ӧ�Ӯ_�F�I�v\n",
                "�Ǵ˻��D�G�u�b�~�H�H�O�����H�F�A�b�~�H�ڸ̴N�u���u�j�~�H�v�Ӥw�I�v\n",
                "�Ǵ˻��D�G�u�o�@�ɤW�����\���b�~�H���s�b�I�v\n",
    }) );
}

void relay_say(object ob, string arg)
{
    if( arg == "�b�~�H" )  {
        do_chat( ({ "�Ǵ˻��D�G�u�b�~�H�O�ӧC�H���رڡA�~�H�N�~�H�٦��@�b���H��b�O�d�����C�v\n",
                    "�Ǵ˻��D�G�u�n�O�A�ٱ��F�b�~�H�A���ҩ��ӵ��ڬݡA�ڷ|���A�n�B���C�v\n",
        }) );
        return;
    }

    if( arg == "�j�~�H" ) {
        do_chat( ({ "�Ǵ˻��D�G�u�ڭ̱j�~�H�O�@�ɤW�̰��j���|���رڤF�A�A�o�C�����å����ڻ��@�I�C�v\n", }) );
        return;
    }
}

int give_check(object ob)
{
    if( ob->id("_CRUSH_BONE_SHINBONE_") ) return 1;        // �H��
    else if( ob->id("_CRUSH_BONE_FOOT_") ) return 2;       // �}�x
    else if( ob->id("_CRUSH_BONE_SKULL_") ) return 3;      // �Y�`
    else if( ob->id("_CRUSH_BONE_RIB_") ) return 4;        // �ذ�
    else if( ob->id("_CRUSH_BONE_WAR_PLAN_") ) return 5;   // �@�ԭp�e
    else if( ob->id("_CRUSH_BONE_BLOOD_") ) return 6;      // ��G
    else return 0;
}

void add_reputation(object me, int value)
{
    me->gain_score("reputation", value );
    tell_object(me, HIW"(�A��o�F " + value + " �I���n��ȡC)\n"NOR);
}

void add_exp(object me, int value)
{
    me->improve_level(value);
    tell_object(me, HIW"(�A��o�F " + value + " �I���g��ȡC)\n"NOR);
}

int give_gold(object me, int amount)
{
    object item;

    if( file_size("obj/money/gold.c") < 0 ) return 0;
    if( catch(item = new("/obj/money/gold.c")) ) return 0;

    item->set_amount(amount);

    if( item->move(me) ) {
        message_vision("$N�q�f�U�̱ǥX�F�@�Ƕ����A�����F$n�C\n", this_object(), me);
    } else {
        if( item->move(environment(me)) ) {
            message_vision("$N�q�f�U�̱ǥX�F�@�Ƕ����A�����F$n�A���O���b�a�W�F�C\n", this_object(), me);
        } else {
            destruct(item);
            return 0;
        }
    }
    return 1;
}

int give_ht_pill(object me, int amount)
{
    object item;

    if( file_size("/d/crush_bone/npc/obj/ht_pill.c") < 0 ) return 0;
    if( catch(item = new("/d/crush_bone/npc/obj/ht_pill.c")) ) return 0;

    item->set_amount(amount);

    if( item->move(me) ) {
        message_vision("$N�q���˸̱ǥX�F�@�ǰ������A�����F$n�C\n", this_object(), me);
    } else {
        if( item->move(environment(me)) ) {
            message_vision("$N�q���˸̱ǥX�F�@�ǰ������A�����F$n�A���O���b�a�W�F�C\n", this_object(), me);
        } else {
            destruct(item);
            return 0;
        }
    }
    return 1;
}


void add_record(object me, int value)
{
    string id = me->query_id();
    if( undefinedp(record[id]) ) record[id] = value;
    else record[id] = record[id] + value;
    tell_object(me, HIW"(�A��o�F " + value + " �I���n���C)\n"NOR);
    this_object()->save();
}

int give_gift(object me, string no)
{
    object item;

    if( file_size(gift[no]["file"]) < 0 ) return 0;
    if( catch(item = new(gift[no]["file"])) ) return 0;

    if( item->move(me) ) {
        message_vision("$N�q�I�᮳�X" + item->name() + "��$n�C\n", this_object(), me);
    } else {
        if( item->move(environment(me)) ) {
            message_vision("$N�q�I�᮳�X" + item->name() + "��$n�A���O���b�a�W�F�C\n", this_object(), me);
        } else {
            destruct(item);
            return 0;
        }
    }
    return 1;
}

int accept_object(object me, object ob)
{
    if( is_busy() ) {
        tell_object(me, "��西�b���L���A�е��@�U�C\n");
        return 0;
    }
    if( is_fighting() ) {
        do_chat((: command, "say �O�n�I�S�ݨ�ڥ��b���[�ڡI" :));
        return 0;
    }

    if( give_check(ob) && !ob->move(this_object()) ) {
        tell_object(me, "�����G�S��k�@�����o��h���F��A�γ\�O�ӭ��F�A�i�H�յۤ��u�����C\n");
        return 0;
    }


    me->start_busy(1);
    this_object()->start_busy(1);

    switch( give_check(ob) ) {
        case 0:
            do_chat((: command, "say �o�O���򪱷N��A���}�I" :));
            return 0;
        break;

        case 1: 
            if( start == -1 ) { if( !give_ht_pill(me, ob->query_amount()) ) return 0; }
            else add_record(me, ob->query_amount());
        break;

        case 2:
            if( start == -1 ) { add_exp(me, ob->query_amount()*100 ); }
            else add_record(me, ob->query_amount());
        break;

        case 3:
            if( start == -1 ) { if( !give_gold(me, ob->query_amount()*3) ) return 0; }
            else add_record(me, ob->query_amount());
        break;

        case 4:
            if( start == -1 ) { add_reputation(me, ob->query_amount()*5); }
            else add_record(me, ob->query_amount()*10);
        break;

        case 5:
            if( start == -1 ) { return 0; }
            else add_record(me, ob->query_amount()*25);
        break;

        case 6:
            if( start == -1 ) {
                if( do_trigger("on") ) { call_out("do_trigger", 1800, "off"); }
                return 1;
            }
            else add_record(me, ob->query_amount()*50);
        break;
    }

    message_vision("$N�������ݵ�" + ob->short() + "���D�G�u�����A�o�N��F�A�b�~�H�N�O�Ӧ��ڡI�v\n", this_object() );

    ob->set_amount(0);
    do_chat( ({ ( : destruct , ob : ), }) );

    return 1;
}

int do_trigger(string arg)
{
    if( arg == "on" && start == -1 ) {
        start = 1;
        message("system", "\n"HIW+this_object()->name()+"�g���D�G���a�I���a�I��H���몺�b�~�H�����a�I�I\n\n"NOR ,users());
    }

    if( arg == "off" && start == 1 ) {
        start = -1;
        message("system", "\n"HIW+this_object()->name()+"�g���D�G�������I����ӴN�ǤF�H���몺�b�~�H�a�A�즹����I�I\n\n"NOR ,users());
    }
    save();
    return 1;
}

int do_wizset(string arg)
{
    int value;
    string player;

    if( sscanf(arg, "%s %d", player, value) != 2 ) return 0;
    
    record[player] = value;
    this_object()->save();

    return notify_fail("wizset ok.\n");
}

int do_wizclear(string arg)
{
    if( arg ) map_delete(record, arg);
    else 
    record = ([]);
    return notify_fail("wizclear ok.\n");
}
int do_list(string arg)
{
    int i, j, size;
    string *players, msg, temp;

    if( start != 1 ) return 0;

    players = keys(record);
    size = sizeof(players);
    
    for(i=0;i<size-1;i++)
        for(j=i+1;j<size;j++) {
            if( record[players[i]] < record[players[j]] ) {
                temp = players[i];
                players[i] = players[j];
                players[j] = temp;
            }
        }

    msg  = "�ٱ��H����b�~�H�Ʀ�G\n";
    msg += "----------------------\n";

    for(i=0;i<size;i++)
      if( this_player()->query("id") == players[i] )
            msg += sprintf(HIY"%3d. %-12s: %-5d\n"NOR, i+1, players[i], record[players[i]]);
        else
            msg += sprintf("%3d. %-12s: %-5d\n", i+1, players[i], record[players[i]]);

    msg += "----------------------\n";
    
    this_player()->start_more(msg);

    return 1;
}

int do_receive(string arg)
{
    int i, size;
    string *no, msg;

    if( start != 1 ) return 0;

    no = keys(gift);
    size = sizeof(no);

    if( !arg || undefinedp(gift[arg]) ) {
        msg = "�i���������y�C��G\n";
        msg += "------------------------------------------------------------\n";
        msg += " �s��    �n��    ���~                             \n";
        msg += "------------------------------------------------------------\n";
        for(i=0;i<size;i++)
            msg += sprintf("%5s    %4d    %s\n", no[i], gift[no[i]]["need"], gift[no[i]]["name"] );
        msg += "------------------------------------------------------------\n";
        this_player()->start_more(msg);
    } else {
        if( undefinedp(record[this_player()->query_id()]) ) return notify_fail("�A���n�������A�L�k�������y�C\n");
        if( record[this_player()->query_id()] < gift[arg]["need"] ) return notify_fail("�A���n�������A�L�k�������y�C\n");
        if( give_gift(this_player(), arg) ) {
            record[this_player()->query_id()] = record[this_player()->query_id()] - gift[arg]["need"];
            if( record[this_player()->query_id()] <= 0 ) map_delete(record, this_player()->query_id());
        }
        else return notify_fail("�A�b������y�ɡA���G�o�ͤF����N�~�C\n");
    }

    return 1;
}

int do_start()
{
    int i, amount, count=0;
    string file;
    object mob, room;

    if( start != 1 ) return 1;

    do_chat( ({ "�Ǵ˻��D�G�u�[�ݱƦW�Glist �A���~�C��Greceive �A���Greceive <�s��> �v\n", }) );

    for(i=0;i<sizeof(mob_file);i++) {

        file = file_path + "npc/" + mob_file[i];
        amount = sizeof(children(file));

        if( amount < mob_amount[i] ) {
            amount = mob_amount[i] - amount;

            // ���ͦܤ@�w�ƶq�� Mob
            while( amount-- ) {

                count++;
                if( count > 30 ) { return 1; }
                mob = new(file);

                // �d�Ҫ����ťH�U��MOB
                if( i<=3 ) room = load_object( file_path + mob_born1[random(sizeof(mob_born1))] );
                // �x�Ϊ����ťH�W��MOB
                else room = load_object( file_path + mob_born2[random(sizeof(mob_born2))] );

                if( !mob->move(room) ) {
                    destruct(mob);
                    continue;
                }
            }
        }        
    }
}

