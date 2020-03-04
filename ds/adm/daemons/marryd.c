// marryd.c
#include <marry.h>
#include <ansi.h>
inherit F_DBASE;
inherit F_SAVE;

mapping	marry_house;
mapping	marry_baby;

string *do_sort_record(string type,string *keys);
void resort_record();

void create()
{
        seteuid(getuid());
        if( !restore() )
        {
		marry_house =
		([
       			"h0" : 	([
       				"created":	1,
				"bought":	0,
				"ppl1" :	"none1",
				"ppl2" :	"none2",
				"locate" :	"/open/world2/shengsan/marryhome/data/housedata/samplehouse",
				"childnum" :	0,
				"short" :	"�R���p��",
				"long" :	"�঳�@���ݩ�ۤv���Фl�@���H�ӳ��O�j�����H�ҧV�O���ؼСA�ӳo\n���ЫΥ��n�i�H�����w�B�k�k���ݨD�C�p�G�z�R�U�F�o���y�R���p�ۡz�A\n�z�N�|�o�{�o�B�H�ͪ��׭��䬰�z���a�x�ұa�Ӫ��غئn�B�A���n�S�ݤF\n�A�o��n���Фl���n���P�C�@�i�s�i��N�K�b�G�i��(notice)�W�C",
				]),
		]);
        	marry_baby =
        	([
        		"h0" :	([
				"child1" :	([
						"babyroom" : "/open/world2/shengsan/marryhome/data/housedata/samplebabyhouse",
						"id" : "child1",
						"level" : 1,
						"title" : "BABY",
						"name" : "�p�Ĥ@",
						"sk1" : "babysk1",
						"sk1lv" : 1,
						]),
        			]),
        	]);
        }
        else
        {
        	if( !mapp(marry_house) ) marry_house = ([]);
        	if( !mapp(marry_baby) ) marry_baby = ([]);
        }
        //save();
}

string query_save_file() { return DATA_DIR + "marry"; }

int creat_basehouse(string houseid)
{
	marry_house[houseid] = ([]);
	marry_house[houseid]["created"] = 1;
	marry_house[houseid]["bought"] = 0;
	marry_house[houseid]["ppl1"] = "";
	marry_house[houseid]["ppl2"] = "";
	marry_house[houseid]["locate"] = "";
	marry_house[houseid]["childnum"] = 0;
	marry_house[houseid]["short"] = "�R���p��";
	marry_house[houseid]["long"] = "�঳�@���ݩ�ۤv���Фl�@���H�ӳ��O�j�����H�ҧV�O���ؼСA�ӳo\n���ЫΥ��n�i�H�����w�B�k�k���ݨD�C�p�G�z�R�U�F�o���y�R���p�ۡz�A\n�z�N�|�o�{�o�B�H�ͪ��׭��䬰�z���a�x�ұa�Ӫ��غئn�B�A���n�S�ݤF\n�A�o��n���Фl���n���P�C�@�i�s�i��N�K�b�G�i��(notice)�W�C";
	return 1;
}

int set_house_ppl1(string houseid,string str)
{
	marry_house[houseid]["ppl1"] = str;
	save();
	return 1;
}

int set_house_ppl2(string houseid,string str)
{
	marry_house[houseid]["ppl2"] = str;
	save();
	return 1;
}

int set_house_locate(string houseid,string str)
{
	marry_house[houseid]["locate"] = str;
	save();
	return 1;
}

int set_house_childnum(string houseid,int num)
{
	marry_house[houseid]["childnum"] = num;
	save();
	return 1;
}

int add_house_childnum(string houseid,int num)
{
	if(undefinedp(marry_house[houseid]["childnum"]))
		return 0;
	marry_house[houseid]["childnum"] += num;
	save();
	return 1;
}

int set_house_short(string houseid,string str)
{
	marry_house[houseid]["short"] = str;
	save();
	return 1;
}

int set_house_long(string houseid,string str)
{
	marry_house[houseid]["long"] = str;
	save();
	return 1;
}

int query_house_created(string houseid)
{
	if(undefinedp(marry_house[houseid]))
		return 0;
	else
		return 1;
}

string query_house_short(string houseid)
{
	string str = "";
	if(!undefinedp(marry_house[houseid]["short"]))
		str = marry_house[houseid]["short"];
	return str;
}

int query_house_bought(string houseid)
{
	int i = 0;
	if(!undefinedp(marry_house[houseid]["bought"]))
		i = marry_house[houseid]["bought"];
	return i;
}

string query_house_long(string houseid)
{
	string str = "";
	if(!undefinedp(marry_house[houseid]["long"]))
		str = marry_house[houseid]["long"];
	return str;
}

