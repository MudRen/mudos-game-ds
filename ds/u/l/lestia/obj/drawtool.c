// color drawer

inherit ITEM;

#include <ansi.h>

void create()
{

        set_name(HIC+"�ۦ�u��"+NOR,({"drawing tool","draw","tool"}));
        set("long",@LONG
�o�O Lestia �M�Ϊ��ۦ�u��, �p�G�����D���δN Help draw �a
Help draw �٤����D���δN�h�� Lestia �a, �ݧ� Lestai �٬O����
�����, ���A�N�h���@���a..:P
LONG
        );
        set("unit","��");
        setup();
}

void init()
{
        if( this_player() == environment() ) {
        add_action("do_draw","draw");
        add_action("do_help","help");
        }
}

string ansi_color( string str );

int do_draw(string arg)
{
        string file,str;
        object me;

        me = this_player();
        if(!arg) return notify_fail("�A�n�N���@���ɵۦ�H\n");
        if( file_size(arg) > 0 ) file = arg;
        else if( file_size(arg+".c") > 0) file = arg+".c";
        else if( file_size( me->query("cwd")+arg ) > 0 ) file = me->query("cwd")+arg;
        else if( file_size( me->query("cwd")+arg+".c" ) > 0 ) file = me->query("cwd")+arg+".c";
        else return notify_fail("���o���ɮ׶�\n");
        str = read_file(file);
        str = ansi_color(str);
        write_file(file,str,1);
        tell_object(me,"�g�J���\\n");
        return 1;
}

int do_help(string arg)
{
        if(!arg || arg != "draw") return 0;
        else write(@HELP
�o�ӫ��O�O�N�H�U������r��@�ഫ�R

$BLK$ - �¦�            $NOR$ - ��_���`�C��
$RED$ - ����            $HIR$ - �G����
$GRN$ - ���            $HIG$ - �G���
$YEL$ - �g����          $HIY$ - ����
$BLU$ - �`�Ŧ�          $HIB$ - �Ŧ�
$MAG$ - �L����          $HIM$ - ������
$CYN$ - �ź��          $HIC$ - �ѫC��
$WHT$ - �L�Ǧ�          $HIW$ - �զ�

HELP
);
        return 1;
}

string ansi_color( string str )
{
        str = replace_string(str, "$BLK$", BLK);
        str = replace_string(str, "$RED$", RED);
        str = replace_string(str, "$GRN$", GRN);
        str = replace_string(str, "$YEL$", YEL);
        str = replace_string(str, "$BLU$", BLU);
        str = replace_string(str, "$MAG$", MAG);
        str = replace_string(str, "$CYN$", CYN);
        str = replace_string(str, "$WHT$", WHT);
        str = replace_string(str, "$HIR$", HIR);
        str = replace_string(str, "$HIG$", HIG);
        str = replace_string(str, "$HIY$", HIY);
        str = replace_string(str, "$HIB$", HIB);
        str = replace_string(str, "$HIM$", HIM);
        str = replace_string(str, "$HIC$", HIC);
        str = replace_string(str, "$HIW$", HIW);
        str = replace_string(str, "$NOR$", NOR);

// str = replace_string(str, "$HBRED$", HBRED);
// str = replace_string(str, "$HBGRN$", HBGRN);
// str = replace_string(str, "$HBYEL$", HBYEL);
// str = replace_string(str, "$HBBLU$", HBBLU);
// str = replace_string(str, "$HBCYN$", HBCYN);
//  str = replace_string(str, "$HBWHT$", HBWHT);
//  str = replace_string(str, "$BRED$", HBRED);
// str = replace_string(str, "$BGRN$", HBGRN);
//  str = replace_string(str, "$BYEL$", HBYEL);
//  str = replace_string(str, "$BBLU$", HBBLU);
//   str = replace_string(str, "$BMAG$", HBMAG);
//  str = replace_string(str, "$BCYN$", HBCYN);
//  str = replace_string(str, "$BWHT$", HBWHT);

/*
        str = replace_string(str, "$BLINK$", BLINK);
        str = replace_string(str, "$SAVEC$", SAVEC);
        str = replace_string(str, "$REST$", REST);
        str = replace_string(str, "$U$", U);
        str = replace_string(str, "$HIREV$", HIREV);
        str = replace_string(str, "$REV$", REV);
        str = replace_string(str, "$CLR$", CLR);
        str = replace_string(str, "$BEEP$", "");
        str = replace_string(str, "$BOLD$", BOLD);
        str = replace_string(str, "$FRBOT$", FRBOT);
        str = replace_string(str, "$FRTOP$", FRTOP);
        str = replace_string(str, "$UNFR$", UNFR);
*/

        return str;
}

