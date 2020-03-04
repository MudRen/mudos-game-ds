//edit by -Acme-

#include <ansi2.h>
inherit ITEM;
#define VERSION "�ٸ����ܾ�-DS��(A1.0)"
string make_rank(string arg);
void create()
{
        set_name( VERSION , ({"change rank", "rank" }));

        set_weight(1);

        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 10);
                set("rigidity", 10);
                set("long",@LONG

�@���NICK,NAME,TITLE���Q���A�ݰ_�ӤQ���U�Q�A�Фp�ߨϥΡC

���O�榡�G change_nick  <�r��>
           change_name  <�r��>
           change_title <�r��>
           change_rank  <�r��>

$BLK$�V�¦�  $HBK$�V�G��  $BBLK$�V�I���¦�  $NOR$�V��_���`��
$RED$�V����  $HIR$�V�G��  $BRED$�V�I������  $HBRED$�V�I���G��
$GRN$�V���  $HIG$�V�G��  $BGRN$�V�I�����  $HBGRN$�V�I���G��
$YEL$�V�g��  $HIY$�V�G��  $BYEL$�V�I������  $HBYEL$�V�I���G��
$BLU$�V�`��  $HIB$�V�G��  $BBLU$�V�I���Ŧ�  $HBBLU$�V�I���G��
$MAG$�V�L��  $HIM$�V����  $BMAG$�V�I���L��  $HBMAG$�V�I���G��
$CYN$�V�ź�  $HIC$�V�ѫC  $BCYN$�V�I���ź�  $HBCYN$�V�I���ź�
$WHT$�V�L��  $HIW$�V�G��                    $HBWHT$�V�I���զ�
             $BLINK$�V�{�{     $REV$�V�ϥ�
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
        if( !arg ) return notify_fail("�A�n�擄��NICK�H\n");
        arg = make_rank(arg)+NOR;
        write("�A�N�A��NICK�令 " + arg + " �C\n");
        this_player()->set("nickname", arg );
        return 1;
}
int do_name(string arg)
{
        if( !arg ) return notify_fail("�A�n�擄��NAME�H\n");
        arg = make_rank(arg)+NOR;
        write("�A�N�A��NAME�令 " + arg + " �C\n");
        this_player()->set("name", arg );
        return 1;
}
int do_title(string arg)
{
        if( !arg ) return notify_fail("�A�n�擄��TITLE�H\n");
        arg = make_rank(arg)+NOR;
        write("�A�N�A��TITLE�令 " + arg + " �C\n");
        this_player()->set("title", arg );
        return 1;
}
int do_rank(string arg)
{
        if( !arg ) return notify_fail("�A�n�擄��RANK�H\n");
        arg = make_rank(arg)+NOR;
        write("�A�N�A��RANK�令 " + arg + " �C\n");
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

