/* god.c ������ by -Acme-
   �o�O�@�ӱ���MUD�̦U��GAME���a��...
*/

#include <ansi2.h>

#define GHOST_WAR_MOB_DIR "/open/world1/acme/big_ghost_war/"

inherit F_SAVE;
inherit ROOM;

mapping GAMES = ([ "����`": ([ 
                       "LEADER" : "/u/a/acme/mud_game/ma_game/npc/moon.c",
                       "PLACE" : "/u/a/acme/workroom.c"
                   ]),

                   "�s�]�ûR": ([
                       "LEADER" : "/open/world1/acme/area2/npc/xie.c",
                       "PLACE" : "/open/world1/acme/area2/t50.c",
                       "MOB_PLACE" : ({
                           // ���a��
                           "/open/world1/tmr/area/square",
                           "/open/world1/tmr/area/ms1",
                           "/open/world1/tmr/area/ms3",
                           "/open/world1/tmr/area/vroad1",
                           "/open/world1/tmr/area/vroad3",
                           "/open/world1/tmr/area/glade",
                           "/open/world1/tmr/area/river_road",
                           "/open/world1/tmr/area/street1",
                           "/open/world1/tmr/area/day_lake",

                           // �����s(�ⶳ�x)
                           "/open/world1/acme/bonze/b1",
                           "/open/world1/acme/bonze/b3",
                           "/open/world1/acme/bonze/b18",
                           "/open/world1/acme/bonze/b5",
                           "/open/world1/acme/bonze/b7",
                           "/open/world1/acme/bonze/b9",
                           "/open/world1/acme/bonze/b11",
                           "/open/world1/acme/bonze/b14",

                           // �ⶳ�p
                           "/open/world1/tmr/advbonze/hill3",
                           "/open/world1/tmr/advbonze/hill7",
                           "/open/world1/tmr/freezetaoism/footway2",
                           "/open/world1/tmr/freezetaoism/hill1",
                           "/open/world1/tmr/freezetaoism/observatory2",

                           // �H���D�[
                           "/open/world1/tmr/freezetaoism/temple1",
                           "/open/world1/tmr/freezetaoism/temple4",
                           "/open/world1/tmr/freezetaoism/temple6",

                           // ���F��
                           "/open/world1/wilfred/sand/room1",
                           "/open/world1/wilfred/sand/room4",
                           "/open/world1/wilfred/sand/room6",
                           "/open/world1/wilfred/sand/room8",
                           "/open/world1/wilfred/sand/room10",
                           "/open/world1/wilfred/sand/room13",
                           "/open/world1/wilfred/sand/room16",
                           "/open/world1/wilfred/sand/room25",
                           "/open/world1/wilfred/sand/room20",

                           // �������
                           "/open/world1/wilfred/meadow/room19",
                           "/open/world1/wilfred/meadow/room24",
                           "/open/world1/wilfred/meadow/room35",
                           "/open/world1/wilfred/meadow/room21"
                           "/open/world1/wilfred/meadow/room7",
                           "/open/world1/wilfred/meadow/room10",

                           // �B�F��
                           "/open/world1/cominging/area/bsouth2",
                           "/open/world1/cominging/area/bsouth",
                           "/open/world1/cominging/area/boo-lin2",
                           "/open/world1/cominging/area/boo-lin",
                           "/open/world1/cominging/area/bwest1",
                           "/open/world1/cominging/area/bwest3",
                           "/open/world1/cominging/area/bwest5",
                           "/open/world1/cominging/area/beast3",
                           "/open/world1/cominging/area/bnorth1",
                           "/open/world1/cominging/area/bnorth4",

                           // �����s
                           "/open/world1/cominging/purple_sun/1f3",
                           "/open/world1/cominging/purple_sun/2f2",
                           "/open/world1/cominging/purple_sun/3f2",
                           "/open/world1/cominging/purple_sun/4f2",
                           "/open/world1/cominging/purple_sun/hole5",

                           // �L����
                           "/open/world1/wu_sha_town/seacoun4",
                           "/open/world1/wu_sha_town/seacoun6",
                           "/open/world1/wu_sha_town/seacoun21",
                           "/open/world1/wu_sha_town/seacoun27",
                           "/open/world1/wu_sha_town/seacoun30",
                           "/open/world1/wu_sha_town/seacoun39",

                           // �ѫ���s
                           "/open/world1/acme/area/f1",
                           "/open/world1/acme/area/pass4",
                           "/open/world1/acme/area/lea1",
                           "/open/world1/acme/area/lea3",
                           "/open/world1/acme/area/farm1",

                           // �ѫ�
                           "/open/world1/acme/area/st",
                           "/open/world1/acme/area/plaza1",
                           "/open/world1/acme/area/street6",
                           "/open/world1/acme/area/pathway2",
                           "/open/world1/acme/area/plaza2",
                           "/open/world1/acme/area/street3",

                           // �ѫ��Ū�
                           "/open/world1/acme/cominging/passage2",
                           "/open/world1/acme/cominging/way1",
                           "/open/world1/acme/cominging/way3",
                           "/open/world1/acme/cominging/path1",
                           "/open/world1/acme/cominging/path3",
                           "/open/world1/acme/cominging/path5",
                           "/open/world1/acme/cominging/path8",

                           // �ѫ��I��
                           "/open/world1/acme/area2/p3",
                           "/open/world1/acme/area2/p5",
                           "/open/world1/acme/area2/p14",
                           "/open/world1/acme/area2/p16",
                           "/open/world1/acme/area2/p7",
                       }),
                       "TUNE" : 0,
                   ]),
                ]);

mapping big_ghost_mob;

void open_big_ghost_war();
void big_ghost_war_addmob();
string get_object(object who);
int tune_game(string game);
int query_tune_game(string game);
int do_dest_all_ghost();
int do_list_all_ghost();

void create()
{
    set("short", "������");
    set("long", "���a�O���O���Ҧb......\n");

    set("name", "������");
    set("id", "Acme");

    if( !restore() ) {
        big_ghost_mob=([]);
        this_object()->save();
    }
    setup();
}

string query_save_file() { return "/u/a/acme/data/big_ghost_war"; }

void init()
{
    if( wizhood(this_player()) == "(admin)" ) {
        add_action( "do_trigger", "trigger" );
        add_action( "do_dest_all_ghost", "dest_all_ghost" );
        add_action( "do_list_all_ghost", "list_all_ghost" );
    }
}

int do_trigger(string arg)
{
    int i;
    string *game=keys(GAMES),msg="";
    object leader;

    if( !arg ) return notify_fail("�A�QĲ�o���򬡰ʡH\n");
    if( ( i=member_array( arg, game)) == -1 )
        return notify_fail("�S���o�Ӭ��ʮ@�I\n");       
        
    /* �o�Ӭ��ʤ��P�A�t�gfunction */
    if( arg == "�s�]�ûR") {
        /* ���椤�N�O�I�s�F */
        if( GAMES["�s�]�ûR"]["TUNE"] ) return 1;
        open_big_ghost_war();
        return 1;
    }

    CHANNEL_D->do_channel(this_object(), "sys", "���ʡG" + arg + "�Ұ�..." );

    if( leader=new(GAMES[game[i]]["LEADER"]) ) {
        CHANNEL_D->do_channel(this_object(), "sys", "������J�G"+ GAMES[game[i]]["LEADER"] + " ���\\..." );
        if( leader->move(GAMES[game[i]]["PLACE"]) ) {
            message("system", "\n\t\t"HIW"�i"HIG"�ѼƲ��H"HIW"�j"NOR+
                    leader->query("name")+ NOR"�r�ۥն��A�Ʒn�����{�H��......\n\n",
                    users());
        }
    } else CHANNEL_D->do_channel(this_object(), "sys", "������J�G"+ GAMES[game[i]]["LEADER"] + " ����..." );

    return 1;
}

void open_big_ghost_war()
{
    object xie;
    string msg;

    /* ���椤�N�O�ҰʤF */
    if( GAMES["�s�]�ûR"]["TUNE"] ) return;

    /* find object '�Ѵݨ�' */
    xie = find_living("__XIE__");

    if( !objectp(xie) ) {
        CHANNEL_D->do_channel(this_object(), "sys", "�Ԫ� �s�]�ûR �Ұ�..." );
        CHANNEL_D->do_channel(this_object(), "sys", "������J�G" + GAMES["�s�]�ûR"]["LEADER"] + " ����..(MOB�٨S�_��)");
        return;
    } else {
        if( !xie->query("way_point") ) {
        CHANNEL_D->do_channel(this_object(), "sys", "�Ԫ� �s�]�ûR �Ұ�..." );
        CHANNEL_D->do_channel(this_object(), "sys", "������J�G" + GAMES["�s�]�ûR"]["LEADER"] + " ���\\..");
        }
    }

    /* xie �b�}war �U��N���A���� */
    if( xie->query("way_point") ) return;

    if( !xie->move(GAMES["�s�]�ûR"]["PLACE"]) ) {
        CHANNEL_D->do_channel(this_object(), "sys", "���󲾰ʡG" + GAMES["�s�]�ûR"]["PLACE"] + " ����..");
        return;
    } else CHANNEL_D->do_channel(this_object(), "sys", "���󲾰ʡG" + GAMES["�s�]�ûR"]["PLACE"] + " ���\\..");

    msg = "\n\t\t"HIW"�i"HIG"�ѼƲ��H"HIW"�j"NOR+xie->query("name")+NOR"�a�۸U�~�\\�����ʾ]�s�b�h...\n\n";
    message("system", msg, users() );

    /* �N�}war�v�浹 '�Ѵݨ�' */
    if( !xie->query("way_point") ) xie->go_open_war();

    return;
}

/* �W�[ big ghost war mob */
void big_ghost_war_addmob()
{
    int i, j;
    string *mobs, *mob_dir, str, name;
    object mob, room;
    /* �S���椤�N�O�[�F */
    if( !GAMES["�s�]�ûR"]["TUNE"] ) return;

    if( sizeof(big_ghost_mob) > 1 )
        mobs = keys(big_ghost_mob);

    /* check mob */
    for(i=0;i<sizeof(mobs);i++) {
        // mob ����
        if( !objectp(mob = find_object(mobs[i])) ) {
            map_delete(big_ghost_mob, mobs[i]);
            continue;
        }

        // mob �S����
        if( !environment(mob) ) {
            map_delete(big_ghost_mob, mobs[i]);
            destruct(mob);
            continue;
        }

        // ��smob����
        mobs[i] = file_name(environment(mob));
    }


    /* MOB �p��99���ɫh�W�[ */
    i = sizeof(mobs);
    if( i < 99 ) {
        mob_dir = get_dir(GHOST_WAR_MOB_DIR);
        i = 99-i;
        if( i > 20 ) i = 20;
        while( i-- ) {
            j = random(sizeof(mob_dir));
            if( file_size(GHOST_WAR_MOB_DIR + mob_dir[j] ) == -1 ) continue; // �S�o��
            if( file_size(GHOST_WAR_MOB_DIR + mob_dir[j] ) == -2 ) continue; // �O�ؿ�
            mob = new( GHOST_WAR_MOB_DIR + mob_dir[j] );
            if( !objectp(mob) ) continue;
            room = load_object(GAMES["�s�]�ûR"]["MOB_PLACE"][random(sizeof(GAMES["�s�]�ûR"]["MOB_PLACE"]))]);
            if( !objectp(room) ) continue;
            if( !mob->move(room) ) continue;
            if( sscanf(get_object(mob),"%s (%s)", str, name) == 2)
                big_ghost_mob[str] = file_name(environment(mob));
        }
    }

    this_object()->save();
    return;
}

string get_object(object who) { return sprintf("%O", who); }

int do_dest_all_ghost()
{
    int i;
    string *mobs, msg;
    object mob;
    if( !mapp(GAMES) || undefinedp(GAMES["�s�]�ûR"]) ) return 0;
    if( undefinedp(GAMES["�s�]�ûR"]["TUNE"]) || !GAMES["�s�]�ûR"]["TUNE"] ) return 0;

    mobs = keys(big_ghost_mob);

    for(i=0;i<sizeof(mobs);i++) {
        // mob ����
        if( !objectp(mob = find_object(mobs[i])) ) {
            map_delete(big_ghost_mob, mobs[i]);
            continue;
        }

        // mob �S����
        if( !environment(mob) ) {
            map_delete(big_ghost_mob, mobs[i]);
            destruct(mob);
            continue;
        }

        // mob �R��
        tell_room(environment(mob), "�Ať��"+mob->query("name")+"���W�o�X�u�����v���n��A�Ʀ��@�}�C�Ϯ����F�C\n");
        map_delete(big_ghost_mob, mobs[i]);
        destruct(mob);
    }

    msg = "\n\t\t"HIW"�i"HIG"�ѼƲ��H"HIW"�j"NOR"�����ܦ�A�ަ��ܭD�A�ѷn�a�ʡA�s�]�h���I�I�I\n\n";
    message("world:world1:vision", msg ,users());
    GAMES["�s�]�ûR"]["TUNE"] = 0;
    this_object()->save();
    return 1;
}

int do_list_all_ghost()
{
    int i;
    string *mobs, msg;
    object mob;

    if( !mapp(GAMES) || undefinedp(GAMES["�s�]�ûR"]) ) return 0;
    if( undefinedp(GAMES["�s�]�ûR"]["TUNE"]) || !GAMES["�s�]�ûR"]["TUNE"] ) return 0;

    msg = "========================= �s�]�ûR =========================\n";
    mobs = keys(big_ghost_mob);
     msg += "\t- �ثe�@��"+sizeof(mobs)+"��Ghost -\n============================================================\n";

    for(i=0;i<sizeof(mobs);i++) {
        // mob ����
        if( !objectp(mob = find_object(mobs[i])) ) {
            map_delete(big_ghost_mob, mobs[i]);
            continue;
        }

        // mob �S����
        if( !environment(mob) ) {
            map_delete(big_ghost_mob, mobs[i]);
            destruct(mob);
            continue;
        }

        // ��smob����
        mobs[i] = file_name(environment(mob));
        msg+= sprintf("�s���G%3d %26s -> %s\n",
              i,mob->query("name") + "(" + mob->query("id") + ")",
              environment(mob)->query("short") + mobs[i]
        );

    }

    msg+= "============================================================\n";

    this_player()->start_more(msg);
    this_object()->save();
    return 1;
}

/* �������ʪ��}�l�P���� */
int tune_game(string game)
{
    if( !mapp(GAMES) || undefinedp(GAMES[game]) ) return 0;
    if( undefinedp(GAMES[game]["TUNE"]) ) GAMES[game]["TUNE"] = 0;
    if( GAMES[game]["TUNE"] == 0 ) GAMES[game]["TUNE"] = 1;
    else GAMES[game]["TUNE"] = 0;
    this_object()->save();
    return 1;
}

/* query���ʬO�_�b���� */
int query_tune_game(string game)
{
    if( !mapp(GAMES) || undefinedp(GAMES[game]) ) return 0;
    if( undefinedp(GAMES[game]["TUNE"]) ) return 0;
    return GAMES[game]["TUNE"];
}

