#include <ansi.h>

inherit ITEM;

string *color = ({ HIM, HIW, RED, GRN, YEL, BLU, MAG, CYN,WHT, HIW });

void speak_message(object me, int flag, string *songs, string target_name);
void speak_end(int flag);

void create()
{
        set_name(GRN"自動點唱機"NOR, ({ "singing machine","machine" }) );
        set("long",
"一台會唱歌的機器, 隸屬於地下城的專有產物(用法: look list)"
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
        CHANNEL_D->do_channel(this_object(),"music","謝謝您的欣賞, 謝謝.");
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
                CHANNEL_D->do_channel(this_object(), "music", HIG+me->name(1)+NOR"點撥了一首歌" + ((target_name) ? "給"+HIC+target_name+NOR : "") + "..。");
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
                return notify_fail(" 有人在點了喔 ! \n");
        if( !arg || ( sscanf(arg, "%d", c) != 1 && sscanf(arg, "%d for %s", c, tar) != 2 ))
                return notify_fail("想要點那首歌曲呢？( singing <第幾首> [for <人>] )\n");

        if( sscanf(arg, "%d for %s", c, tar) == 2 )
        {
                if( !objectp(t=find_player(tar)) )
                        return notify_fail("沒有這個人喔！\n");
                if( t == me )
                        return notify_fail("點給自己..！！\n");
                if( t->query_temp("invis") )
                        return notify_fail("沒有這個人喔！\n");
        }

        if( file_size(n_s="/open/world1/cominging/area/npc/song_info/"+c) == -1 ) return notify_fail("沒這首吧？\n");

        write(HIR"點撥歌曲：第 "+c+" 首。\n"NOR);

        if( !read_file(n_s)
        ||      !arrayp(songs = explode(read_file(n_s) , "\n")))
                return notify_fail(HIR"載入失敗！！\n"NOR);
        this_object()->set_temp("busy", 1);
        this_object()->set("no_fight", 1);
        if( !objectp(t) )
                t = me;
        call_out("speak_message", 1, me, 0, songs, t->name_id());
        return 1;
}



