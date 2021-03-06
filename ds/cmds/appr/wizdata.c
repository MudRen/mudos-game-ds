// wizdata.c

#define WIZdata "/adm/etc/wizdata"
#define WIZSdata "/adm/etc/security/wizsdata"

inherit F_CLEAN_UP;

mapping *wizdata;

int listloop_id(string arg);
int listloop_time(int time);
int listloop_level(string wizlevel);
int listdata(int i);
int showsecurity(string arg);

mapping *read_table(string file);	//luky

int main(object me, string arg)
{
	int i;
	string type,arg2;
	
	seteuid(geteuid(me));
	
	if( file_size(WIZdata)<1 ) return notify_fail("載入檔案失敗！\n");
	//wizdata = NATURE_D->read_table(WIZdata);
	wizdata = read_table(WIZdata);
	if(!wizdata) return notify_fail("載入檔案失敗!!\n");

	if(!arg)
	{
		for(i=0;i<sizeof(wizdata);i++)
			listdata(i);
	}
	if(arg && sscanf(arg,"%s %s",type,arg)!=2)
		return notify_fail("wizdata [-i|-t|-s] [字串]\n");
	if(type=="-i")
	{
		while(1)
		{
			if(sscanf(arg,"%s %s",arg2,arg)!=2)
			{
				listloop_id(arg);
				break;
			}
			else
			{
				listloop_id(arg2);
			}
		}
	}
	else if(type=="-t")
	{
		switch(arg)
		{
			case "past":	listloop_time(1); break;
			case "now":	listloop_time(2); break;
			case "future":	listloop_time(3); break;
			case "notime":	listloop_time(0); break;
			case "admin":
			case "arch":
			case "wizard":
			case "apprentice":
			case "immortal":listloop_level("("+arg+")"); break;
			default:
		}

	}
	else if(type=="-s")
	{
		showsecurity(arg);
	}
	return 1;
}

int listloop_id(string arg)
{
	int i;
	for(i=0;i<sizeof(wizdata);i++)
	{
		if(wizdata[i]["wizid"]==arg)
		{
			listdata(i);
			i = sizeof(wizdata);
		}
	}
	return 1;
}

int listloop_time(int time)
{
	int i;
	string strtime;
	switch(time)
	{
		case 1:	strtime = "古代"; break;
		case 2:	strtime = "現代"; break;
		case 3:	strtime = "未來"; break;
		default: strtime = "超時空";
	}
	for(i=0;i<sizeof(wizdata);i++)
	{
		if(wizdata[i]["wiztime"]==strtime)
		{
			listdata(i);
		}
	}
	return 1;
}

int listloop_level(string wizlevel)
{
	int i;
	string realwizlevel;
	for(i=0;i<sizeof(wizdata);i++)
	{
		
		if(SECURITY_D->get_status(wizdata[i]["wizid"])==wizlevel)
		{
			listdata(i);
		}
	}
	return 1;
}

int listdata(int i)
{
	string wizid, wizlevel, wiztime, wizduty;
	string list;

	wizid = wizdata[i]["wizid"];
	wizlevel = SECURITY_D->get_status(wizid);
	wiztime = wizdata[i]["wiztime"];
	wizduty = wizdata[i]["wizduty"];
	list = sprintf("%-12s%-12s%-8s%-s\n",wizid,wizlevel,wiztime,wizduty);
	write(list);

	return 1;
}

int showsecurity(string arg)
{
	int i;
	string list="\n";
	if( file_size(WIZSdata)<1 )
	{
		write("你的權限不足以查看資料!\n");
		return notify_fail("載入檔案失敗!!\n");
	}
	//wizdata = NATURE_D->read_table(WIZSdata);
	wizdata = read_table(WIZSdata);
		if(!wizdata) return notify_fail("載入檔案失敗!!\n");

	for(i=0;i<sizeof(wizdata);i++)
	{
		if(wizdata[i]["wizid"]==arg)
		{
			list += sprintf("以下資訊為夢幻七域最高機密，請勿流傳至外界，謝謝！！！\n");
			list += sprintf("英文代號：%s\n",wizdata[i]["wizid"]);
			list += sprintf("巫師權限：%s\n",SECURITY_D->get_status(wizdata[i]["wizid"]));
			list += sprintf("姓    名：%s\n",wizdata[i]["realname"]);
			list += sprintf("學校科系：%s\n",wizdata[i]["school"]);
			list += sprintf("電子信箱：%s\n",wizdata[i]["email"]);
			list += sprintf("聯絡地址：%s\n",wizdata[i]["address"]);
			list += sprintf("聯絡電話：%s\n",wizdata[i]["telephone"]);
			list += sprintf("其他資訊：%s\n",wizdata[i]["other"]);
		}
	}
	write(list+"\n");
	return 1;
}
//luky
mapping *read_table(string file)
{
	string *line, *field, *format;
	mapping *data;
	int i, rn, fn;

//	if( file_size(file) <1 ) return ({ });
	line = explode(read_file(file), "\n");
	data = ({});
	for(i=0; i<sizeof(line); i++) {
		if( line[i]=="" || line[i][0]=='#' ) continue;
		if( !pointerp(field) ) {
			field = explode( line[i], ":" );
			continue;
		}
		if( !pointerp(format) ) {
			format = explode( line[i], ":" );
			continue;
		}
		break;
	}

	for( rn = 0, fn = 0; i<sizeof(line); i++) {
		if( line[i]=="" || line[i][0]=='#' ) continue;
		if( !fn ) data += ({ allocate_mapping(sizeof(field)) });
		sscanf( line[i], format[fn], data[rn][field[fn]] );
		fn = (++fn) % sizeof(field);
		if( !fn ) ++rn;
	}
	return data;
}


int help(object me)
{
write(@HELP
指令格式 : wizdata [-i|-t|-s] [字串]

    wizdata		: 列出所有巫師的資料
    wizdata -t [past|now|future|notime|admin|arch|wizard|apprentice|immortal]
    wizdata -i [[id1] [id2] .... [idn]]
    wizdata -s id	: 魔神專用選項

此指令可讓你查詢巫師所屬的時空及職責。
HELP
    );
    return 1;
}
