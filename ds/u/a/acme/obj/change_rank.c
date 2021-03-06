//edit by -Acme-

#include <ansi2.h>
inherit ITEM;
#define VERSION "稱號改變器-DS版(A1.0)"
string make_rank(string arg);
void create()
{
        set_name( VERSION , ({"change rank", "rank" }));

        set_weight(1);

        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("value", 10);
                set("rigidity", 10);
                set("long",@LONG

一把改NICK,NAME,TITLE的利器，看起來十分銳利，請小心使用。

指令格式： change_nick  <字串>
           change_name  <字串>
           change_title <字串>
           change_rank  <字串>

$BLK$–黑色  $HBK$–亮黑  $BBLK$–背景黑色  $NOR$–恢復正常色
$RED$–紅色  $HIR$–亮紅  $BRED$–背景紅色  $HBRED$–背景亮紅
$GRN$–綠色  $HIG$–亮綠  $BGRN$–背景綠色  $HBGRN$–背景亮綠
$YEL$–土黃  $HIY$–亮黃  $BYEL$–背景黃色  $HBYEL$–背景亮黃
$BLU$–深藍  $HIB$–亮藍  $BBLU$–背景藍色  $HBBLU$–背景亮藍
$MAG$–淺紫  $HIM$–粉紅  $BMAG$–背景淺紫  $HBMAG$–背景亮紫
$CYN$–藍綠  $HIC$–天青  $BCYN$–背景藍綠  $HBCYN$–背景藍綠
$WHT$–淺灰  $HIW$–亮白                    $HBWHT$–背景白色
             $BLINK$–閃爍     $REV$–反白
LONG);
        }
        setup();
}

int query_autoload() { return 1; }
void init()
{
        add_action("do_nick","change_nick");
        add_action("do_name","change_name");
        add_action("do_title","change_title");
        add_action("do_rank","change_rank");
}
int do_nick(string arg)
{
        if( !arg ) return notify_fail("你要改什麼NICK？\n");
        arg = make_rank(arg)+NOR;
        write("你將你的NICK改成 " + arg + " 。\n");
        this_player()->set("nickname", arg );
        return 1;
}
int do_name(string arg)
{
        if( !arg ) return notify_fail("你要改什麼NAME？\n");
        arg = make_rank(arg)+NOR;
        write("你將你的NAME改成 " + arg + " 。\n");
        this_player()->set("name", arg );
        return 1;
}
int do_title(string arg)
{
        if( !arg ) return notify_fail("你要改什麼TITLE？\n");
        arg = make_rank(arg)+NOR;
        write("你將你的TITLE改成 " + arg + " 。\n");
        this_player()->set("title", arg );
        return 1;
}
int do_rank(string arg)
{
        if( !arg ) return notify_fail("你要改什麼RANK？\n");
        arg = make_rank(arg)+NOR;
        write("你將你的RANK改成 " + arg + " 。\n");
        this_player()->set("guild_rank", arg );
        return 1;
}
string make_rank(string arg)
{
        arg = replace_string(arg, "$BLK$", BLK);
        arg = replace_string(arg, "$RED$", RED);
        arg = replace_string(arg, "$GRN$", GRN);
        arg = replace_string(arg, "$YEL$", YEL);
        arg = replace_string(arg, "$BLU$", BLU);
        arg = replace_string(arg, "$MAG$", MAG);
        arg = replace_string(arg, "$CYN$", CYN);
        arg = replace_string(arg, "$WHT$", WHT);
        arg = replace_string(arg, "$HBK$", HBK);
        arg = replace_string(arg, "$HIR$", HIR);
        arg = replace_string(arg, "$HIG$", HIG);
        arg = replace_string(arg, "$HIY$", HIY);
        arg = replace_string(arg, "$HIB$", HIB);
        arg = replace_string(arg, "$HIM$", HIM);
        arg = replace_string(arg, "$HIC$", HIC);
        arg = replace_string(arg, "$HIW$", HIW);
        arg = replace_string(arg, "$NOR$", NOR);
        arg = replace_string(arg, "$BBLK$", BBLK);
        arg = replace_string(arg, "$BRED$", BRED);
        arg = replace_string(arg, "$BGRN$", BGRN);
        arg = replace_string(arg, "$BYEL$", BYEL);
        arg = replace_string(arg, "$BBLU$", BBLU);
        arg = replace_string(arg, "$BMAG$", BMAG);
        arg = replace_string(arg, "$BCYN$", BCYN);
        arg = replace_string(arg, "$HBRED$", HBRED);
        arg = replace_string(arg, "$HBGRN$", HBGRN);
        arg = replace_string(arg, "$HBYEL$", HBYEL);
        arg = replace_string(arg, "$HBBLU$", HBBLU);
        arg = replace_string(arg, "$HBMAG$", HBMAG);
        arg = replace_string(arg, "$HBCYN$", HBCYN);
        arg = replace_string(arg, "$HBWHT$", HBWHT);
        arg = replace_string(arg, "$BLINK$", BLINK);
        arg = replace_string(arg, "$REV$", REV);
        return arg;
}

