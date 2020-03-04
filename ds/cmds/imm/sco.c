// score.c
#include <ansi.h>
#include <combat.h>

inherit F_CLEAN_UP;
string attribute_color(int current, int value);
string attitude_report(int evil_value);
string status_color(int current, int max);

void create() { seteuid(ROOT_UID); }

int main(object me, string arg)
{
        object ob,weapon,horse;
        mapping my;
        string line, skill_type, model,*apply_id;
        int attack_points, dodge_points, parry_points;
	int str1,con1,dex1,int1,bio1,bar1,wit1,sou1,tec1;
        seteuid(getuid(me));

        if(!arg) ob = me;
        else
        {
                ob = present(arg, environment(me));
                if (!ob) ob = find_player(arg);
                if (!ob) ob = find_living(arg);
                if (!ob) return notify_fail("你要察看誰的狀態﹖\n");
         	if(!wizardp(me))
         	{
         		if(ob->query("creater")!=me)
			return notify_fail("只有巫師能察看別人的狀態。\n");
          	}
        }
/*--------------------------------------------------------------------------*/
        my = ob->query_entire_dbase();  //做資料轉換.
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
if( objectp(weapon = ob->query_temp("weapon")) )
                skill_type = weapon->query("skill_type");
        else skill_type = "unarmed";
// ★☆★☆★☆★☆★☆
switch(ob->money_type())
{

case 1:
model=
"╭──────────────────────────────────────●\n"
"│  %12s  " HIW " %-52s"NOR"\n"
"╰──────────────────────────────────────╮\n"
"╭──────────╮  等級 "HIY"%3d "NOR"級   年齡 "HIM"%2d "NOR"歲   種族 "HIG"%-6s"NOR"  性別 "HIC"%-2s"NOR"   │\n"
"│"HIW"夢幻七域"NOR" 之 "HIY"古代時空"NOR"├───────────────────────────○\n"
"├──────────╯生物(BIO)：%s%2d"NOR"(%2d)   生命點數(HP)：%s%5d"NOR" / %-5d       │\n"
"│力量(STR)：%s%3d"NOR"(%3d)   獸性(BAR)：%s%2d"NOR"(%2d)   魔法點數(MP)：%s%5d"NOR" / %-5d       │\n"
"│體質(CON)：%s%3d"NOR"(%3d)   魔法(WIT)：%s%2d"NOR"(%2d)   內勁點數(AP)：%s%5d"NOR" / %-5d       │\n"
"│智慧(INT)：%s%3d"NOR"(%3d)   心靈(SOU)：%s%2d"NOR"(%2d)   戰鬥熟練度  ： %-10d         │\n"
"│敏捷(DEX)：%s%3d"NOR"(%3d)   科技(TEC)：%s%2d"NOR"(%2d)   經 驗 值    ： %-10d         │\n"
"○──────────────────────────────────────○\n"
"│物理攻擊力： %-4d     攻擊命中率：  %3d   個 性 態 度 ： %14s"NOR"     │\n"
"│物理防禦力： %-4d     閃躲迴避率：  %3d   擊 殺 生 物 ： "HIY"%-14d"NOR"     │\n"
"│心靈抵抗力： %-4d     聲      望： %-5d  擊 殺 玩 家 ： "HIR"%-14d"NOR"     │\n"
"○──────────────────────────────────────○\n";
	break;
case 2:
model=
"◤￣￣￣￣￣￣◥"NOR"�灨w�灨w�灨w�灨w�灨w�灨w"HIY"【"HIW"夢幻七域"HIY"】"NOR"─�灨w�灨w�灨w�灨w�灨w◆\n"NOR
"▏%12s " HIW "     %-52s"NOR"\n"
"◣＿＿＿＿＿＿◢      �歈������������������������������������������������龤墦n"
"◎�������������������龤� 等級 "HIY"%3d "NOR"級  年齡 "HIM"%2d "NOR"歲   種族 "HIG"%-6s"NOR" 性別 "HIC"%-2s"NOR"  �鱋n"
"��    "HIG"現 代 時 空"NOR"     �僓������������������踛����������������������������龤墦n"
"◎�������������������龤極耵�(BIO)：%s%2d"NOR"(%2d) │生命點數(HP)：%s%5d"NOR" / %-5d   │\n"
"│力量(STR)：%s%3d"NOR"(%3d) │獸性(BAR)：%s%2d"NOR"(%2d) │魔法點數(MP)：%s%5d"NOR" / %-5d   │\n"
"│體質(CON)：%s%3d"NOR"(%3d) │魔法(WIT)：%s%2d"NOR"(%2d) │內勁點數(AP)：%s%5d"NOR" / %-5d   │\n"
"│智慧(INT)：%s%3d"NOR"(%3d) │心靈(SOU)：%s%2d"NOR"(%2d) │戰鬥熟練度  ： %-10d     │\n"
"│敏捷(DEX)：%s%3d"NOR"(%3d) │科技(TEC)：%s%2d"NOR"(%2d) │經 驗 值    ： %-10d     │\n"
"□──────────┴─────────┴───────────────□\n"
"�曭垓z攻擊力： %-4d     攻擊命中率：  %3d   個 性 態 度 ： %14s"NOR" �鱋n"
"�曭垓z防禦力： %-4d     閃躲迴避率：  %3d   擊 殺 生 物 ： "HIY"%-14d"NOR" �鱋n"
"�齯葅F抵抗力： %-4d     知  名  度： %-5d  擊 殺 玩 家 ： "HIR"%-14d"NOR" �鱋n"
"□────────────────────────────────────□\n";
	break;
case 3:
model=
"╭──────────────────────────────────────●\n"
"│  %12s  " HIW " %-52s"NOR"\n"
"╰──────────────────────────────────────╮\n"
"╭──────────╮  等級 "HIY"%3d "NOR"級   年齡 "HIM"%2d "NOR"歲   種族 "HIG"%-6s"NOR"  性別 "HIC"%-2s"NOR"   │\n"
"│"HIW"夢幻七域"NOR" 之 "HIC"未來時空"NOR"├───────────────────────────○\n"
"├──────────╯生物(BIO)：%s%2d"NOR"(%2d)   生命點數(HP)：%s%5d"NOR" / %-5d       │\n"
"│力量(STR)：%s%3d"NOR"(%3d)   獸性(BAR)：%s%2d"NOR"(%2d)   魔法點數(MP)：%s%5d"NOR" / %-5d       │\n"
"│體質(CON)：%s%3d"NOR"(%3d)   魔法(WIT)：%s%2d"NOR"(%2d)   內勁點數(AP)：%s%5d"NOR" / %-5d       │\n"
"│智慧(INT)：%s%3d"NOR"(%3d)   心靈(SOU)：%s%2d"NOR"(%2d)   戰鬥熟練度  ： %-10d         │\n"
"│敏捷(DEX)：%s%3d"NOR"(%3d)   科技(TEC)：%s%2d"NOR"(%2d)   經 驗 值    ： %-10d         │\n"
"○──────────────────────────────────────○\n"
"│物理攻擊力： %-4d     攻擊命中率：  %3d   個 性 態 度 ： %14s"NOR"     │\n"
"│物理防禦力： %-4d     閃躲迴避率：  %3d   擊 殺 生 物 ： "HIY"%-14d"NOR"     │\n"
"│心靈抵抗力： %-4d     聲      望： %-5d  擊 殺 玩 家 ： "HIR"%-14d"NOR"     │\n"
"○──────────────────────────────────────○\n";
	break;
default:
model=
"╭──────────────────────────────────────●\n"
"│  %12s  " HIW " %-52s"NOR"\n"
"╰──────────────────────────────────────╮\n"
"╭──────────╮  等級 "HIY"%3d "NOR"級   年齡 "HIM"%2d "NOR"歲   種族 "HIG"%-6s"NOR"  性別 "HIC"%-2s"NOR"   │\n"
"│"HIW"夢幻七域"NOR" 之 "HIW"夢幻時空"NOR"├───────────────────────────○\n"
"├──────────╯生物(BIO)：%s%2d"NOR"(%2d)   生命點數(HP)：%s%5d"NOR" / %-5d       │\n"
"│力量(STR)：%s%3d"NOR"(%3d)   獸性(BAR)：%s%2d"NOR"(%2d)   魔法點數(MP)：%s%5d"NOR" / %-5d       │\n"
"│體質(CON)：%s%3d"NOR"(%3d)   魔法(WIT)：%s%2d"NOR"(%2d)   內勁點數(AP)：%s%5d"NOR" / %-5d       │\n"
"│智慧(INT)：%s%3d"NOR"(%3d)   心靈(SOU)：%s%2d"NOR"(%2d)   戰鬥熟練度  ： %-10d         │\n"
"│敏捷(DEX)：%s%3d"NOR"(%3d)   科技(TEC)：%s%2d"NOR"(%2d)   經 驗 值    ： %-10d         │\n"
"○──────────────────────────────────────○\n"
"│物理攻擊力： %-4d     攻擊命中率：  %3d   個 性 態 度 ： %14s"NOR"     │\n"
"│物理防禦力： %-4d     閃躲迴避率：  %3d   擊 殺 生 物 ： "HIY"%-14d"NOR"     │\n"
"│心靈抵抗力： %-4d     聲      望： %-5d  擊 殺 玩 家 ： "HIR"%-14d"NOR"     │\n"
"○──────────────────────────────────────○\n";
}

line += sprintf(model
,
RANK_D->query_rank(ob), sizeof(apply_id=ob->query_temp("apply/id"))? ob->short(1)+"  『 " +apply_id[sizeof(apply_id)-1]+" 』" : ob->short(1),
ob->query("level"),ob->query("age"),to_chinese(ob->query("race")),ob->query("gender"),
attribute_color(bio1,my["Merits"]["bio"]),bio1,my["Merits"]["bio"],
status_color(my["hp"], my["max_hp"]), my["hp"], my["max_hp"],
attribute_color(str1,my["str"]),str1,my["str"],	//參考 /feature/attribute.c
attribute_color(bar1,my["Merits"]["bar"]),bar1,my["Merits"]["bar"],
status_color(my["mp"],my["max_mp"]),my["mp"],my["max_mp"],
attribute_color(con1,my["con"]),con1,my["con"],
attribute_color(wit1,my["Merits"]["wit"]),wit1,my["Merits"]["wit"],
status_color(my["ap"],my["max_ap"]),my["ap"],my["max_ap"],
attribute_color(int1,my["int"]),int1,my["int"],
attribute_color(sou1,my["Merits"]["sou"]),sou1,my["Merits"]["sou"],
ob->query("combat_exp"),
attribute_color(dex1,my["dex"]),dex1,my["dex"],
attribute_color(tec1,my["Merits"]["tec"]),tec1,my["Merits"]["tec"],
ob->query("exp"),
ob->query_damage(),
COMBAT_D->attack_factor(ob,skill_type),
attitude_report(ob->query("evil")),
ob->query_armor(),
-COMBAT_D->dodge_factor(ob,"dodge"),
my["MKS"] + my["PKS"],
ob->query_shield(),
my["popularity"],
my["PKS"]
);
if(mapp(my=ob->query("wound")))
{
	apply_id=keys(my);
	for(str1=0;str1<sizeof(apply_id);str1++)
	{
		if(ob->query("wound/"+apply_id[str1])>0)
		line += sprintf(HIW"  "+to_chinese(apply_id[str1])+"受傷程度:%s%3d%%\n"NOR,status_color(100-ob->query("wound/"+apply_id[str1]),100),ob->query("wound/"+apply_id[str1]));
	}
}

if(horse=ob->query_temp("ride"))
 line += sprintf("\n  你正坐在%s上。\n"NOR,horse->name());
line +="\n";
write(line);
return 1;

}
string attitude_report(int evil_value)
{
 string outcome;
 outcome = "";
 if(!evil_value) evil_value = 0;
	if( evil_value > 800 ) outcome += HIR "如同惡魔般邪惡";
	else if( evil_value >= 600 ) outcome += HIM"極度凶殘      ";
	else if( evil_value >= 400 ) outcome += HIM"十分邪惡      ";
	else if( evil_value >= 200 ) outcome += HIY"非常頑劣      ";
	else if( evil_value >= 50 ) outcome += HIY"有點惡劣      ";
	else if( evil_value >= -50 ) outcome += "安分守己      ";
	else if( evil_value >= -200 ) outcome += HIG"略為善良      ";
	else if( evil_value >= -400 ) outcome += HIG"相當善良      ";
	else if( evil_value >= -600 ) outcome += HIW"樂善好施      ";
	else if( evil_value >= -800 ) outcome += HIW"俠義心腸      ";
	else outcome += HIC "有如天使般神聖";

 outcome += NOR;
 return outcome;
}
string attribute_color(int current, int value)
{
        if( current > value ) return HIW;
        if( current == value ) return NOR;
        if( current < value ) return HBK;
}
string status_color(int current, int max)
{
        int percent;

        if( max ) percent = current * 100 / max;
        else percent = 100;
        if( percent > 100 ) return HIC;
        if( percent >= 80 ) return HIG;
        if( percent >= 60 ) return HIY;
        if( percent >= 30 ) return HIM;
        return HIR;

}

int help(object me)
{
        write(@HELP
指令格式 : sc
	   sc 自己的招喚生物
           sc <對象名稱>                   (巫師專用)

這個指令可以顯示你(妳)或指定對象(含怪物)的基本資料。

see also : hp
HELP
    );
    return 1;
}

