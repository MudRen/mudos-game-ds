/*

 )))) Cominging Board File 化 ((((

 File 格式:
<作者>;<時間>;<篇名>
<文章內容>

'| board  |'
'|  file  |'
'| system |'

ESC"[1;7m"BLK"| board  |"NOR" "ESC"[1;7m"
ESC"[1;7m"BLK"|  file  |"NOR" "ESC"[1;7m"
ESC"[1;7m"BLK"| system |"NOR" "ESC"[1;7m"

*/
#include <ansi.h>
#define DEFAULT_DATA_DIR "/u/c/cominging/board/"

inherit ITEM;
string *postz;

void done_post(object me, int time, string subject, string locate, string text);
int atoi(string arg);
string *query_postz() { return postz; }

void read_board(string dir, object me)
{
        string *textz;
        string *file;
        string str;

        textz = allocate(4);
        str = "\n";

        if( file_size(dir) == -1 )
                me->start_more("這個留言是空的。\n");
        file = explode(read_file(dir), "\n");
        if( sizeof(file) < 2 || sizeof(explode(file[0], ";")) != 3 )
                me->start_more("檔案儲存格式錯誤，請通知巫師。\n");
        textz[0] = explode(file[0],";")[0];
        textz[1] = explode(file[0],";")[1];
        textz[2] = explode(file[0],";")[2];
        file = file[1..sizeof(file)-1];
        textz[3] = implode(file, "\n");

        str += sprintf(ESC"[1;37;46m Ｄ"NOR" "ESC"[1;37;44m  作者  "NOR" %-s\n", textz[0]);
	str += sprintf(ESC"[1;37;46m   "NOR" "ESC"[1;37;44m  時間  "NOR" %-s\n", ctime(atoi(textz[1])));
        str += sprintf(ESC"[1;37;46m Ｓ"NOR" "ESC"[1;37;44m  主題  "NOR" %-s\n", textz[2]);
        str += WHT"＿＿＿＿＿＿＿＿＿＿＿＿文　章　內　容＿＿＿＿＿＿＿＿＿＿＿＿\n"NOR;
        str += textz[3] + "\n";
        me->start_more(str);
}

int create_dir(string file)
{
        string path, *dir;
        int i, tmp;

        tmp = 0;

        dir = explode(file, "/");
        path = "/";
        for(i=0; i<sizeof(dir); i++) {
                path += dir[i];
                if( mkdir(path) )
                        tmp++;
                path += "/";
        }
        return tmp;
}

void setup()
{
        seteuid(ROOT_UID);
        if( !query("board_id") )
        {
                write("請設定 board_id。\n");
                return;
        }
        set("no_get", 1);
        set("no_sac", 1);
        set("no_clean_up", 1);
        if( !query("unit") )
                set("unit", "面");
        if( file_size(DEFAULT_DATA_DIR+query("board_id")) != -2 )
        {
                if( !create_dir(DEFAULT_DATA_DIR+query("board_id")) )
                {
                        write("建立此版專屬目錄失敗。\n");
                        return;
                }
        }
        postz = get_dir(DEFAULT_DATA_DIR+ query("board_id") + "/");
        postz = sort_array(postz, 1);
}

string short()
{
        int counter;
        object me;
        string last_read;

        me = this_player();
        counter = 0;
        last_read = me->query("file_board_last_read/"+ query("board_id"));

        if( !arrayp(postz) || sizeof(postz) < 1 )
                return ::short() + " [無任何留言]";
        for(int x=0;x<sizeof(postz);x++)
                if( atoi(postz[x][0..strlen(postz[x])-2]) > atoi(last_read) )
                        counter++;
        if( counter )
                return sprintf("%s [%|3d篇留言 %|3d篇未讀]", ::short(), sizeof(postz), counter);
        else return sprintf("%s [%|3d篇留言]", ::short(), sizeof(postz));
}

void init()
{
        add_action("do_read", "nread");
        add_action("do_post", "npost");
        add_action("do_discard", "ndiscard");
}

int do_read(string arg)
{
        object me;
        int flag, x;
        string last_read;

        me = this_player();
        last_read = me->query("file_board_last_read/"+ query("board_id"));

        if( !arg )
                return notify_fail("指令格式: nread <篇數>|new \n");
        if( sizeof(postz) == 0 )
                return notify_fail("並無任何的留言。\n");
        if( arg == "new" )
        {
                for(x=0;x<sizeof(postz);x++)
                        if( atoi(postz[x][0..strlen(postz[x])-2]) > atoi(last_read) )
                        {
                                flag = 1;
                                break;
                        }
                if( flag )
                {
			me->set("file_board_last_read/"+ query("board_id"), postz[x][0..strlen(postz[x])-2]);
                        read_board(DEFAULT_DATA_DIR+ query("board_id")+ "/"+ postz[x], me);
                }
                else return notify_fail("無新留言。\n");
                return 1;
        }
        if( sscanf(arg, "%d", flag) != 1 )
                return notify_fail("指令格式: nread <篇數>|new \n");
        if( flag > sizeof(postz) || flag < 1)
                return notify_fail("好像沒有這篇留言吧..。\n");
        if( atoi(postz[flag-1][0..strlen(postz[x])-2]) > atoi(last_read) )
                me->set("file_board_last_read/"+ query("board_id"), postz[flag-1][0..strlen(postz[flag-1])-2]);
        read_board(DEFAULT_DATA_DIR+ query("board_id")+ "/"+ postz[flag-1], me);
        return 1;
}

int do_post(string arg)
{
        object me;

        me = this_player();

        if( !arg ) return notify_fail("指令格式: post <文章標題>\n");
        me->edit((: done_post, me, time(), arg, DEFAULT_DATA_DIR+query("board_id")+"/"+time()+"a" :));
        return 1;
}

void done_post(object me, int time, string subject, string locate, string text)
{
        string write, sign;
        int temp = 97;

        write = "";
        sign = sprintf ("%ssignature/%s/%s.sig",DATA_DIR, (string)getuid(me)[0..0], getuid(me));

        while(1)
        {
                if( file_size(locate)!=-1 )
                        locate = locate[0..strlen(locate)-2]+ sprintf("%c", ++temp);
                else break;
        }
        write += implode( ({ me->name_id(1), ""+time, subject }), ";") +"\n";
        write += text;
	write += (file_size(sign))? "\n--\n"+read_file(sign)+"--\n": "";
        if( write_file(locate, write, 1) )
                tell_object(me, "留言完畢。\n");
        else tell_object(me, "留言失敗, 可能是寫入留言權限不足。\n");
        setup();
}

int do_discard(string arg)
{
        object me;
        string *masters, master, file;
        int flag;

        me = this_player();
	seteuid(geteuid(me));

        if( !arg )
                return notify_fail("指令格式: ndiscard <篇數>\n");
        if( sscanf(arg, "%d", flag) != 1 )
                return notify_fail("指令格式: ndiscard <篇數>\n");
        if( arrayp(query("master")) )
                masters = query("master");
        else masters = ({ });
        if( stringp(query("master")) )
                master = query("master");
        else master = "";
        if( sizeof(postz) < 1 )
                return notify_fail("現在沒有任何留言可以刪喔。\n");
        if( member_array(getuid(me) , masters) == -1
        && SECURITY_D->get_wiz_level(me) < 5
        && getuid(me) != master )
                return notify_fail("你沒有刪除這篇文章的權利。\n");
        if( flag > sizeof(postz) || flag < 1 )
                return notify_fail("不正確的篇數。\n");
        file = DEFAULT_DATA_DIR+ query("id") + "/" +postz[flag-1];
        if( rm(file) )
        {
                write("文章篇數 "+ flag + " 刪除成功\。\n");
                return 1;
        }
        else return notify_fail("刪除文章篇數 "+ flag +"失敗，可能是因為存取權限不夠。\n");
        return 1;
}

int atoi(string arg)
{
        int s = strlen(arg);
        int *x = allocate(s);
        int tmp, tmp2;

        for(int z=(s-1);z>-1;z--) // '0' == 49
        {
                if( arg[z..z] == "1" ) x[s-z-1] = 1;
                else if( arg[z..z] == "2" ) x[s-z-1] = 2;
                else if( arg[z..z] == "3" ) x[s-z-1] = 3;
                else if( arg[z..z] == "4" ) x[s-z-1] = 4;
                else if( arg[z..z] == "5" ) x[s-z-1] = 5;
                else if( arg[z..z] == "6" ) x[s-z-1] = 6;
                else if( arg[z..z] == "7" ) x[s-z-1] = 7;
                else if( arg[z..z] == "8" ) x[s-z-1] = 8;
                else if( arg[z..z] == "9" ) x[s-z-1] = 9;
                else if( arg[z..z] == "0" ) x[s-z-1] = 0;
                else x[s-z-1] = 0;
        }
        for(int y=0;y<s;y++)
        {
                tmp2 = x[y];
                if( y > 0 )
                        for(int b=0;b<y;b++)
                                tmp2 *= 10;
                tmp += tmp2;
        }
        return tmp;
}
