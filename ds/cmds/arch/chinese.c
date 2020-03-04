#include <ansi2.h>
inherit F_CLEAN_UP;

// color() add by -Acme-
string color(string msg)
{
        if( !msg ) return 0;
        msg = replace_string(msg, "$BLK$", BLK);
        msg = replace_string(msg, "$RED$", RED);
        msg = replace_string(msg, "$GRN$", GRN);
        msg = replace_string(msg, "$YEL$", YEL);
        msg = replace_string(msg, "$BLU$", BLU);
        msg = replace_string(msg, "$MAG$", MAG);
        msg = replace_string(msg, "$CYN$", CYN);
        msg = replace_string(msg, "$WHT$", WHT);
        msg = replace_string(msg, "$HBK$", HBK);
        msg = replace_string(msg, "$HIR$", HIR);
        msg = replace_string(msg, "$HIG$", HIG);
        msg = replace_string(msg, "$HIY$", HIY);
        msg = replace_string(msg, "$HIB$", HIB);
        msg = replace_string(msg, "$HIM$", HIM);
        msg = replace_string(msg, "$HIC$", HIC);
        msg = replace_string(msg, "$HIW$", HIW);

        msg = replace_string(msg, "$BBLK$", BBLK);
        msg = replace_string(msg, "$BRED$", BRED);
        msg = replace_string(msg, "$BGRN$", BGRN);
        msg = replace_string(msg, "$BYEL$", BYEL);
        msg = replace_string(msg, "$BBLU$", BBLU);
        msg = replace_string(msg, "$BMAG$", BMAG);
        msg = replace_string(msg, "$BCYN$", BCYN);

        msg = replace_string(msg, "$HBRED$", HBRED);
        msg = replace_string(msg, "$HBGRN$", HBGRN);
        msg = replace_string(msg, "$HBYEL$", HBYEL);
        msg = replace_string(msg, "$HBBLU$", HBBLU);
        msg = replace_string(msg, "$HBMAG$", HBMAG);
        msg = replace_string(msg, "$HBCYN$", HBCYN);
        msg = replace_string(msg, "$HBWHT$", HBWHT);

        msg = replace_string(msg, "$NOR$", NOR);
        msg = replace_string(msg, "$U$", U);
        msg = replace_string(msg, "$BLINK$", BLINK);
        msg = replace_string(msg, "$REV$", REV);

        return msg;
}

int main(object me, string arg)
{
        string key, chinz;

        if( !arg || arg=="" )
                return notify_fail("���O�榡�Rchinese <�^��>==<����>\n");
        if( sscanf(arg, "%s==%s", key, chinz)==2 )
        {
                if(chinz=="none")
                {
                        if(to_chinese(key)==key) return notify_fail(key+" �|���w�q.\n");
                        CHINESE_D->remove_translate(key);
                        write( key + " Removed.\n");
                        return 1;
                }
                chinz = color(chinz);
                CHINESE_D->add_translate(key, chinz);
                write( key + " == " + chinz + "\nOk.\n");
                return 1;
        }
        else if(arg=="DUMP")
                write(CHINESE_D->dump_translate(0));
        else write(arg+" == "+to_chinese(arg)+"\n");
        return 1;
}

int help()
{
        write ( @HELP
���O�榡�Rchinese �^��==����
          chinese �^��==none
          chinese �^��
          chinese DUMP
HELP
        );
        return 1 ;
}
