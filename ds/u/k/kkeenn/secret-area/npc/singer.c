#include <ansi.h>

inherit ITEM;

string *color = ({ HIM, HIW, RED, GRN, YEL, BLU, MAG, CYN,WHT, HIW });

void speak_message(object me, int flag, string *songs, string target_name);
void speak_end(int flag);

void create()
{
        set_name(GRN"�۰��I�۾�"NOR, ({ "singing machine","machine" }) );
        set("long",
"�@�x�|�ۺq������, ���ݩ�a�U�����M������(�Ϊk: look list)"
);
        set("no_sac",1);
         set("can_talk",1);
        set("no_get",1);           setup();
}

void init()
{
        add_action("do_sing","singing");
}

string query_color()
{
        return color[random(sizeof(color))];
}

void speak_end(object me)
{
        CHANNEL_D->do_channel(this_object(),"music","���±z���Y��, ����.");
        this_object()->delete_temp("busy");
        this_object()->delete("no_fight");
}

void speak_message(object me, int flag, string *songs, string target_name)
{
        object *user = users();
        if( flag > sizeof(songs) -1 )
        {
                call_out("speak_end", 0, me);
                return;
        }
        if( flag == 0 && target_name != me->name_id())
                CHANNEL_D->do_channel(this_object(), "music", HIG+me->name(1)+NOR"�I���F�@���q" + ((target_name) ? "��"+HIC+target_name+NOR : "") + "..�C");
        CHANNEL_D->do_channel(this_object(),"music", query_color()+songs[flag]+NOR);
        call_out("speak_message", 4+random(3) , me, ++flag, songs, target_name);
}

int do_sing(string arg)
{
        string *songs, file_w, n_s, *a, tar;
        int c;
        object me, t;

        me = this_player();

        if( query_temp("busy") )
                return notify_fail(" ���H�b�I�F�� ! \n");
        if( !arg || ( sscanf(arg, "%d", c) != 1 && sscanf(arg, "%d for %s", c, tar) != 2 ))
                return notify_fail("�Q�n�I�����q���O�H( singing <�ĴX��> [for <�H>] )\n");

        if( sscanf(arg, "%d for %s", c, tar) == 2 )
        {
                if( !objectp(t=find_player(tar)) )
                        return notify_fail("�S���o�ӤH��I\n");
                if( t == me )
                        return notify_fail("�I���ۤv..�I�I\n");
                if( t->query_temp("invis") )
                        return notify_fail("�S���o�ӤH��I\n");
        }

        if( file_size(n_s="/open/world1/cominging/area/npc/song_info/"+c) == -1 ) return notify_fail("�S�o���a�H\n");

        write(HIR"�I���q���G�� "+c+" ���C\n"NOR);

        if( !read_file(n_s)
        ||      !arrayp(songs = explode(read_file(n_s) , "\n")))
                return notify_fail(HIR"���J���ѡI�I\n"NOR);
        this_object()->set_temp("busy", 1);
        this_object()->set("no_fight", 1);
        if( !objectp(t) )
                t = me;
        call_out("speak_message", 1, me, 0, songs, t->name_id());
        return 1;
}



