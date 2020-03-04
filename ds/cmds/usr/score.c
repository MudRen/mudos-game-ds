// score.c
#include <ansi2.h>
#include <combat.h>

#define WAR_SCORE_BAR  "                                                                     "

inherit F_CLEAN_UP;
string attribute_color(int current, int value);
string attitude_report(int evil_value);
string status_color(int current, int max);
string query_element_chinese(string elm);
void create() {
    seteuid(ROOT_UID);
}

string getWarScoreBar(int war_score) {
    int len, max;
    string result;
    len = strlen(WAR_SCORE_BAR);
    max = 10000;
    result =  sprintf(HBGRN"%s"HBBLU"%s"NOR,
                      WAR_SCORE_BAR[0..(len*war_score/max)] + NOR,
                      WAR_SCORE_BAR[ (len*war_score/max)+1..(len-1)]);
    return result + "%5.2f�H";
}

// uncolor() add by -Acme-
string uncolor(string msg)
{
    if ( !msg ) return 0;
    msg = replace_string(msg, BLK, "");
    msg = replace_string(msg, RED, "");
    msg = replace_string(msg, GRN, "");
    msg = replace_string(msg, YEL, "");
    msg = replace_string(msg, BLU, "");
    msg = replace_string(msg, MAG, "");
    msg = replace_string(msg, CYN, "");
    msg = replace_string(msg, WHT, "");
    msg = replace_string(msg, HBK, "");
    msg = replace_string(msg, HIR, "");
    msg = replace_string(msg, HIG, "");
    msg = replace_string(msg, HIY, "");
    msg = replace_string(msg, HIB, "");
    msg = replace_string(msg, HIM, "");
    msg = replace_string(msg, HIC, "");
    msg = replace_string(msg, HIW, "");

    msg = replace_string(msg, BBLK, "");
    msg = replace_string(msg, BRED, "");
    msg = replace_string(msg, BGRN, "");
    msg = replace_string(msg, BYEL, "");
    msg = replace_string(msg, BBLU, "");
    msg = replace_string(msg, BMAG, "");
    msg = replace_string(msg, BCYN, "");

    msg = replace_string(msg, HBRED, "");
    msg = replace_string(msg, HBGRN, "");
    msg = replace_string(msg, HBYEL, "");
    msg = replace_string(msg, HBBLU, "");
    msg = replace_string(msg, HBMAG, "");
    msg = replace_string(msg, HBCYN, "");
    msg = replace_string(msg, HBWHT, "");

    msg = replace_string(msg, NOR, "");
    msg = replace_string(msg, U, "");
    msg = replace_string(msg, BLINK, "");
    msg = replace_string(msg, REV, "");

    return msg;
}

// getConditionBuffer() add by -Acme-
string getConditionBuffer(object ob) {
    int cnt;
    string tmp, msg, buf, sk;
    mapping buffering;

    buffering = ob->query_conditions();

    msg = "";
    cnt = 0;
    if ( sizeof(buffering) ) {
        foreach(buf in keys(buffering) ) {
//            if( undefinedp(buffering[buf]) ) continue;
//            if( !mapp(buffering[buf]) ) continue;

            tmp = "";
            cnt++;
            sk = uncolor( to_chinese(buf) );

            if ( cnt == 1 ) tmp += "�x";
            tmp += sprintf("%-19s", sk + "("+ buffering[buf] + ")");
            tmp = replace_string(tmp, sk, to_chinese(buf) );
            if ( cnt%4 == 0 ) {
                cnt = 0;
                tmp += "\n";
            }
            msg += tmp;
        }
        if ( cnt != 0 ) msg += "\n";
        msg += "���w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w��\n";
    }

    return msg;
}

int main(object me, string arg)
{
    object ob,weapon,horse;
    mapping my;
    string line, skill_type, model,*apply_id;
    int str1,con1,dex1,int1,bio1,bar1,wit1,sou1,tec1;

    
    seteuid(getuid(me));

    if (!arg) ob = me;
    else
    {
        ob = present(arg, environment(me));
        if (!ob) ob = find_player(arg);
        if (!ob) ob = find_living(arg);
        if (!ob) return notify_fail("�A�n��ݽ֪����A�S\n");
        if (!wizardp(me))
        {
            if (ob->query("creater")!=me)
                return notify_fail("�u���Ův���ݧO�H�����A�C\n");
        }
    }
    /*--------------------------------------------------------------------------*/
    my = ob->query_entire_dbase();  //������ഫ.
    line = "";
    //CHINESE_D->chinese_date(((int)ob->query("birthday") - 14*365*24*60) * 60)
    str1= ob->query_str();
    con1= ob->query_con();
    dex1= ob->query_dex();
    int1= ob->query_int();
    bio1= ob->query_bio();
    bar1= ob->query_bar();
    sou1= ob->query_sou();
    wit1= ob->query_wit();
    tec1= ob->query_tec();
    /*-------------------------------------------------------------*/
    if ( objectp(weapon = ob->query_temp("weapon")) )
        skill_type = weapon->query("skill_type");
    else skill_type = "unarmed";

    model=
        "�~�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w��\n"
        "�x  %12s  " HIW " %-52s"NOR"\n"
        "���w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�t\n"
        "�~�w�w�w�w�w��  ���� "HIY"%3d "NOR"��   �~�� "HIM"%2d "NOR"��   �ر� "HIG"%-6s"NOR"  �ʧO "HIC"%-2s"NOR"\n"
        "�x"HIW"�ڤۤC��"NOR"  �u�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w��\n"
        "�u�w�w�w�w�w��          �ͪ�(BIO)�G%s%2d"NOR"(%2d)   �ͩR(HP)�G%s%6d"NOR" / %-6d         �x\n"
        "�x�O�q(STR)�G%s%3d"NOR"(%3d)   �~��(BAR)�G%s%2d"NOR"(%2d)   �]�k(MP)�G%s%6d"NOR" / %-6d         �x\n"
        "�x���(CON)�G%s%3d"NOR"(%3d)   �]�k(WIT)�G%s%2d"NOR"(%2d)   ���l(AP)�G%s%6d"NOR" / %-6d         �x\n"
        "�x���z(INT)�G%s%3d"NOR"(%3d)   ���F(SOU)�G%s%2d"NOR"(%2d)   �������a�G %-10d             �x\n"
        "�x�ӱ�(DEX)�G%s%3d"NOR"(%3d)   ���(TEC)�G%s%2d"NOR"(%2d)   �����ͪ��G %-10d             �x\n"
        "���w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w��\n"
        "�x�� �� �O�G %-5d      �����ޥ��G %-5d    �g �� �ȡG %-14d         �x\n"
        "�x�� �� �v�G %-3d%%       �{���ޥ��G %-5d    �n    ��G %-14d         �x\n"
        "�x�����ˮ`�G %-3d%%       ���z���m�G %-5d    �԰����N�G %-14d         �x\n"
        "�x������ܡG %-3d%%       �]�k���m�G %-5d    �өʺA�סG %14s"NOR"         �x\n"
        "���w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w��\n"
        + "�x" + getWarScoreBar( ob->query("war_score") ) + NOR"�x\n"
        +"���w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w��\n";


    line += sprintf(model,
                    RANK_D->query_rank(ob), sizeof(apply_id=ob->query_temp("apply/id"))? ob->short()+"  �y " +apply_id[sizeof(apply_id)-1]+" �z" : ob->short(),
                    ob->query("level"),ob->query("age"),to_chinese(ob->query("race")),ob->query("gender"),
                    attribute_color(bio1,my["Merits"]["bio"]),bio1,my["Merits"]["bio"],
                    status_color(my["hp"], my["max_hp"]), my["hp"], my["max_hp"],
                    attribute_color(str1,my["str"]),str1,my["str"], //�Ѧ� /feature/attribute.c
                    attribute_color(bar1,my["Merits"]["bar"]),bar1,my["Merits"]["bar"],
                    status_color(my["mp"],my["max_mp"]),my["mp"],my["max_mp"],
                    attribute_color(con1,my["con"]),con1,my["con"],
                    attribute_color(wit1,my["Merits"]["wit"]),wit1,my["Merits"]["wit"],
                    status_color(my["ap"],my["max_ap"]),my["ap"],my["max_ap"],

                    attribute_color(int1,my["int"]),int1,my["int"],
                    attribute_color(sou1,my["Merits"]["sou"]),sou1,my["Merits"]["sou"],
                    my["PKS"],

                    attribute_color(dex1,my["dex"]),dex1,my["dex"],
                    attribute_color(tec1,my["Merits"]["tec"]),tec1,my["Merits"]["tec"],
                    my["PKS"]+my["MKS"],

                    ob->query_damage(),
                    COMBAT_D->basic_attack_factor(ob),
                    my["exp"],

                    ob->query_hit(),
                    COMBAT_D->basic_dodge_factor(ob),
                    my["popularity"],
                        
                                        ob->query_hitpower(),
                    ob->query_armor(),
                    my["war_art"],

                                        ob->query_hit_against(),
                    ob->query_shield(),
                    attitude_report(ob->query("evil")),

                    ob->query("war_score")*100.0/10000.0
                   );

// add by -Acme-
    line += getConditionBuffer(ob);

    if (mapp(my=ob->query("wound")))
    {
        apply_id=keys(my);
        for (str1=0;str1<sizeof(apply_id);str1++)
        {
            if (ob->query("wound/"+apply_id[str1])>0)
                line += sprintf(HIW"  "+to_chinese(apply_id[str1])+"���˵{��:%s%3d%%\n"NOR,status_color(100-ob->query("wound/"+apply_id[str1]),100),ob->query("wound/"+apply_id[str1]));
        }
    }

//if(str1=ob->query_temp("conditions/poison")) line += sprintf(HIR+"�餺�r���t�q: %d%%\n"+NOR,str1);

    if (horse=ob->query_temp("ride"))
        line += sprintf("\n  �A�����b%s�W�C\n"NOR,horse->name());
    line +="\n";

    write(line);
    return 1;

}
string attitude_report(int evil_value)
{
    string outcome;
    outcome = "";
    if (!evil_value) evil_value = 0;
    if ( evil_value > 800 ) outcome += HIR "�p�P�c�]�머�c";
    else if ( evil_value >= 600 ) outcome += HIM"���פ���      ";
    else if ( evil_value >= 400 ) outcome += HIM"�Q�����c      ";
    else if ( evil_value >= 200 ) outcome += HIY"�D�`�x�H      ";
    else if ( evil_value >= 50 ) outcome += HIY"���I�c�H      ";
    else if ( evil_value >= -50 ) outcome += "�w���u�v      ";
    else if ( evil_value >= -200 ) outcome += HIG"�������}      ";
    else if ( evil_value >= -400 ) outcome += HIG"�۷��}      ";
    else if ( evil_value >= -600 ) outcome += HIW"�ֵ��n�I      ";
    else if ( evil_value >= -800 ) outcome += HIW"�L�q�߸z      ";
    else outcome += HIC "���p�Ѩϯ믫�t";

    outcome += NOR;
    return outcome;
}
string attribute_color(int current, int value)
{
    if ( current > value ) return HIW;
    if ( current == value ) return NOR;
    if ( current < value ) return HBK;
}
string status_color(int current, int max)
{
    int percent;

    if ( max ) percent = current * 100 / max;
    else percent = 100;
    if ( percent > 100 ) return HIC;
    if ( percent >= 80 ) return HIG;
    if ( percent >= 60 ) return HIY;
    if ( percent >= 30 ) return HIM;
    return HIR;

}

int help(object me)
{
    write(@HELP
���O�榡 : sccore (�i�Y�g�� sc)
           sc �ۤv���۳�ͪ�
           sc <��H�W��>                   (�Ův�M��)

           �o�ӫ��O�i�H��ܧA(�p)�Ϋ��w��H(�t�Ǫ�)���򥻸�ơC

           see also : hp, help setup
HELP
);
    return 1;
}


