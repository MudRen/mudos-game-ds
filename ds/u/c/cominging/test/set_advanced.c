#include <ansi2.h>
#include <armor.h>
inherit ITEM;

#define BWHT ESC+"[47m"          /* White    */


void create()
{
        set_name(BBLU+HIW"�I�I�I [ver0.2]"NOR, ({ "����F��r�H�ĤG��", "what", "ver0.2" }));
        set_weight(1);
        if( clonep() )
                set_default_object(__FILE__);  
        else
        {
                set("long","�H�H�H�H�H�C\n");
                set("unit","��");
        }
        setup();
}

void init()
{
        object me=this_player();
        add_action("do_rexx","rex");
}

int do_rexx(string a)
{
        object me=this_player();
        string arg, b;
        if( !a || sscanf(a ,"%s %s",b,arg) != 2 ) return notify_fail("[�榡] rex <����> <���e>\n");
        arg = replace_string(arg, "$BLK$", BLK);
        arg = replace_string(arg, "$RED$", RED);
        arg = replace_string(arg, "$GRN$", GRN);
        arg = replace_string(arg, "$YEL$", YEL);
        arg = replace_string(arg, "$BLU$", BLU);
        arg = replace_string(arg, "$MAG$", MAG);
        arg = replace_string(arg, "$CYN$", CYN);
        arg = replace_string(arg, "$WHT$", WHT);
        arg = replace_string(arg, "$HIR$", HIR);
        arg = replace_string(arg, "$HIG$", HIG);
        arg = replace_string(arg, "$HIY$", HIY);
        arg = replace_string(arg, "$HIB$", HIB);
        arg = replace_string(arg, "$HIM$", HIM);
        arg = replace_string(arg, "$HIC$", HIC);
        arg = replace_string(arg, "$HIW$", HIW);
        arg = replace_string(arg, "$NOR$", NOR);

        /* �I���H�Τ@�ǯS�� ANSI �X */

        arg = replace_string(arg, "$HBRED$", HBRED);
        arg = replace_string(arg, "$HBGRN$", HBGRN);
        arg = replace_string(arg, "$HBYEL$", HBYEL);
        arg = replace_string(arg, "$HBBLU$", HBBLU);
        arg = replace_string(arg, "$HBMAG$", HBMAG);
        arg = replace_string(arg, "$HBCYN$", HBCYN);
        arg = replace_string(arg, "$HBWHT$", HBWHT);
        arg = replace_string(arg, "$BBLK$", BBLK);
        arg = replace_string(arg, "$BRED$", BRED);
        arg = replace_string(arg, "$BGRN$", BGRN);
        arg = replace_string(arg, "$BYEL$", BYEL);
        arg = replace_string(arg, "$BBLU$", BBLU);
        arg = replace_string(arg, "$BMAG$", BMAG);
        arg = replace_string(arg, "$BCYN$", BCYN);
        arg = replace_string(arg, "$BWHT$", BWHT);
        arg = replace_string(arg, "$BOLD$", BOLD);
        arg = replace_string(arg, "$CLR$", CLR);
        arg = replace_string(arg, "$HOME$", HOME);
        arg = replace_string(arg, "$REF$", REF);
        arg = replace_string(arg, "$BIGTOP$", BIGTOP);
        arg = replace_string(arg, "$BIGBOT$", BIGBOT);
        arg = replace_string(arg, "$SAVEC$", SAVEC);
        arg = replace_string(arg, "$REST$", REST);
        arg = replace_string(arg, "$BLINK$", BLINK);
        arg = replace_string(arg, "$U$", U);
        arg = replace_string(arg, "$REV$", REV);
        arg = replace_string(arg, "$HIREV$", HIREV);

        me->set(b,arg + NOR);
        write("�����]�w ("+b+")->(" + arg + NOR ")�C\n");
        return 1;
}
