/* Program      : /feature/me.c
 * Author       :Kenny@Eternal.Civilization (3/25/1998)
 *
 * port to chinese wizard group : /feature/vi.c by ken@chinesemud.net (99-3-15)
 */

#include <ansi2.h>                       // �w�q ANSI/VT100 �׺ݾ����h��X

#define ECHO 0                          // Ū����J�ɭn��ܦr��
#define HIDE 1                          // Ū����J�ɤ���ܦr��
#define REFRESH 1                       // Ū����J��n��ø�e��
#define LOGFILE "static/VI"             // �ɮײ��ʰO����

void start_edit(string filename);       // �I�s�s�边�A�}�l�s��
protected void _append(object pl);        // �b��Ы᭱�[�r
protected void _append_line(object pl);   // �b��Щ��U�[�@�s��
protected void _backspace(object pl);     // �R����Ыe���r
protected void _confirm_save(string str, object pl); // ���}�s�边�e�T�{�s��
protected void _del_char(object pl, int bs);      // �R����ФW���r
protected void _del_line(object pl);              // �R�����
protected int  _dispatcher(object pl);            // �������O�줣�P�禡
protected void _down(object pl);                  // ��Щ��U���@��
protected void _end(object pl);                   // �N��в�����
protected void _esc(object pl);                   // �q��J�Ҧ��^��R�O�Ҧ�
protected void _file_end(object pl);              // �N��в����ɧ�
protected void _file_head(object pl);             // �N��в������Y
protected void _goto_line(object pl);             // ����S�w��h
protected void _goto_line_done(string str, object pl, int rein); // ���o�渹
protected void _help(object pl);                  // ���U�e��
protected void _home(object pl);                  // �N��в���歺
protected void _input(string str, object pl, int fresh); // Ū�o��J�r��
protected void _insert(object pl);                // �b��Ыe�����r
protected void _insert_line(object pl);           // �b��ФW��[�@�s��
protected void _insert_exclam_mark(object pl);    // �b��Ыe�����J�@�ӡu!�v�r��
protected void _join(object pl);                  // �N�U���r���즹��᭱
protected void _keymap(object pl);                // �w�q�s�\����
protected void _keymap_done(string str, object pl); // ���o�w�q�\����
protected void _left(object pl);                  // ��Щ������@�r
// �b���A�C��ܰT��
protected varargs void _message(object pl, string str, string callback, int hide,
mixed arg);
protected void _message_done(string str, object pl); // �����T�������
protected void _next_match(object pl);            // �j�M/�����U�ӲŦX�r��
protected void _page_down(object pl);             // ���U���@���]22 ��^
protected void _page_up(object pl);               // ���W���@���]22 ��^
protected void _process(object pl);               // �B�z��J�Ҧ����r���J
protected void _quit(mixed unused, mixed pl);   // ���}�s�边
protected void _refresh(object pl);               // ��s�e��
protected void _refresh_cursor(object pl);        // ��s��Ц�m
// ��ø�e��
protected void _refresh_screen(object pl, int s_row, int e_row, int s_col);
protected void _refresh_status(object pl);        // ��s���A�C
protected void _replace(object pl);               // �r�����
protected void _replace_done(string str, object pl); // ���o�����r��
protected void _right(object pl, int col, int extra);  // ��Щ��k���@�r
protected void _search(object pl);                     // �r��j�M
protected void _search_done(string str, object pl);  // ���o�j�M�r��
protected void _tab(object pl);                        // �R�O�Ҧ��U TAB �䪺�w��
protected void _undef_key(object pl);                  // �����Y�\����w�q
protected void _undef_key_done(string str, object pl); // ���o���w�\����
protected void _up(object pl);                           // ��Щ��W���@��
protected void _write(object pl);                        // ���o�x�s�ɮצW��
protected void _write_done(string str, object pl, int quit); // �x�s�ɮ�

protected mapping EditedFiles=([ ]);              // �s�褤���ɮ�
/*
int iS_Row, iE_Row,                             // �i���������l���渹
    iS_Col, iE_Col,                             // �i���������l�����
    iRow,   iCol,                               // ��Ц�m
    is_Command_Mode, is_NewFile, is_Modify,     // �ɮת��p�X��
    is_Substituted;                             // �N�����X�X��
string *sText,                                  // �ɮפ��e
       sChar, sOldChar,                         // ��J�r��]�R�O�^
       sCount,                                  // �R�O�p��
       sFileName,                               // �s���ɦW
       sSearch, sReplace;                       // �j�M/�����r��
mapping keymap;                                 // �\����w�q��Ӫ�
*/

void start_edit(string file)                // �I�s�s�边�A�}�l�s��
{
        int  i;
        mapping me;


        if (objectp(EditedFiles[file]))
        {
                write(sprintf("%s ���b�s��o���ɮסA�еy�ԦA�s��C\n",
                        capitalize(EditedFiles[file]->query("id"))));
                return;
        } // if
        this_player()->set_temp("me", ([ ]));
        me = this_player()->query_temp("me");
        me["sFileName"] = file;
        if (file_size(file) <= 0)
        {        // �ɮת��פp�� 1
                me["sText"] = ({ "" });
                if (file_size(file) < 0)
                {        // �s��
                        me["is_Command_Mode"] = 0;
                        me["is_NewFile"] = 1;
                }
        }
        else
        {
                string content=read_file(file), tabs="        ";

                // �ɮת��פj�� 0
                me["is_Command_Mode"] = 1;
                me["is_NewFile"] = 0;
                if (stringp(content))
                {
                        me["sText"] = explode(read_file(file), "\n");
                        // �N TAB�A�H 8 �ӪťեN���A�H��K��Ц�m���p��
                        for (i=sizeof(me["sText"])-1; i>=0; i--)
                        {
                                int len=sizeof(me["sText"][i]);
                                reset_eval_cost();
                                for (int j=0; j<len; j++)
                                        if (me["sText"][i][j] == '\t')
                                                me["sText"][i] = replace_string(
							me["sText"][i], "\t", tabs[0..7-j%8]);
                        }
                }
                else me["sText"] = ({ "" });
        } // old file

        me["sCount"] = "";
        me["sSearch"] = me["sReplace"] = me["is_Modify"] = 0;
        me["iE_Row"] = 23;
        me["iS_Row"] = me["iS_Col"] = me["iRow"] = me["iCol"] = 1;
        EditedFiles += ([ file: this_player()->link() ]);

        // ���o/�]�w�\����w�q��Ӫ�
             if (!mapp(me["keymap"] = this_player()->query("me_keymap")))
                     me["keymap"] = ([ ]);
        if (this_player()->query("me_no_help") ||
            this_player()->query_temp("no_me_help"))
        {        // �D�Ĥ@���ϥνs�边�A�����i�J�s�边
                _refresh_screen(this_player(), 1, 23, 1);

                get_char("_input", HIDE, this_player());
        }
        else
        {        // �Ĥ@���ϥνs�边�A���ݥ\�໡��
                this_player()->set_temp("no_me_help", 1);
                _help(this_player());
        }
} // start_edit()


protected void _refresh_cursor(object pl)        // ��s��Ц�m
{
        mapping me=pl->query_temp("me");
        printf(ESC "[%d;%df", me["iRow"]+1, me["iCol"]);
} // _refresh_cursor()


protected void _refresh_status(object pl)        // ��s���A�C
{
        mapping me=pl->query_temp("me");

        // ���ʴ�Ш� (1,1)�A�ΤϬۦr����ܪ��A�C
        printf(HOME + NOR + REV + "�C:%4d ��:%3d %-43s %10s [�R�O�Ҧ�]" + NOR,
                me["iS_Row"]+me["iRow"]-1, me["iS_Col"]+me["iCol"]-1,
                sprintf("%s %s", me["sFileName"], (me["is_Modify"]? "(�w�ק�)":
                (me["is_NewFile"]? "(�s��)": "")))[0..42],
                (me["is_Command_Mode"]? "?:���U�e��": "[��J�Ҧ�]"));
        _refresh_cursor(pl);
} // _refresh_status()


// ��ø�e��
protected void _refresh_screen(object pl, int s_row, int e_row, int s_col)
{
        int  i, temp;
        mapping me=pl->query_temp("me");


        if (e_row < s_row)                // �ˬd�l���渹�����ᦸ��
        {
                temp = e_row;
                e_row = s_row;
                s_row = temp;
        }

        if (s_row < 1) s_row = 1;
        if (s_col < 1) s_col = 1;
        if (e_row > sizeof(me["sText"])) // ����W�L�ɧ�
                e_row = sizeof(me["sText"]);
        if (e_row-s_row > 22) e_row = s_row+22;

        me["iS_Row"] = s_row;        me["iE_Row"] = e_row;
        me["iS_Col"] = s_col;        me["iE_Col"] = s_col+79;

        printf(REF+NOR);                // �M���e���A���ʴ�Ш� (1,1)
        for (i=me["iS_Row"]-1; i<me["iE_Row"]; i++)
                printf("\r\n%s", me["sText"][i][me["iS_Col"]-1..me["iE_Col"]-1]);
        for (i=me["iS_Row"]+22-me["iE_Row"]; i>0; i--)
                printf("\r\n~");        // �����渹�� ~ ���
        _refresh_status(pl);
} // _refresh_screen()


protected void _input(string str, object pl, int fresh) // Ū�o��J�r��
{
        int    i, size, bs=0;
        string *chars;
        mapping me=pl->query_temp("me");

        if (fresh)
        {        // ��ø�e��
                _refresh_screen(pl, me["iS_Row"], me["iE_Row"], me["iS_Col"]);
                get_char("_input", HIDE, pl);
                return;
        }

        me["is_Substituted"] = 1;       // ���]�w�N�����X�X��
        if (str == "")                  // �N���� Backspace/Ctrl-Backspace
        {
                str = "BACKSPACE";
                bs = 1;
        }
        if (str[0] == 27)
        {
                chars = explode(str, ESC);      // �h��X���r��A�H ESC �_�}
                for (i=sizeof(chars)-1; i>=0; i--)
                        chars[i] = ESC + chars[i];      // �[�^ ESC
                if (sizeof(chars) == 0)                 // �Y�u�O��@�r�� ESC
                        chars = ({ ESC });
        }
        else    chars = ({ str });

        size = sizeof(chars);
        for (i=0; i<size; i++)
        {        // �ഫ�h��X���s�边���X
                switch (chars[i])
                {
                case "\t":       me["sChar"] = "TAB";   break;
                case "\r":       me["sChar"] = "ENTER"; break;
                case ESC:        me["sChar"] = "ESC";   break;
                case ESC "OA":
                case ESC "[A":   me["sChar"] = "UP";    break;
                case ESC "OB":
                case ESC "[B":   me["sChar"] = "DOWN";  break;
                case ESC "OC":
                case ESC "[C":   me["sChar"] = "RIGHT"; break;
                case ESC "OD":
                case ESC "[D":   me["sChar"] = "LEFT";  break;
                case ESC "OH":
                case ESC "[H":
                case ESC "1~":
                case ESC "[1~":  me["sChar"] = "HOME";  break;
                case ESC "[2~":  me["sChar"] = "INSERT";break;
                case ESC "[3~":  me["sChar"] = "DELETE";break;
                case ESC "4~":   me["sChar"] = "END";   break;
                case ESC "[4~":  me["sChar"] = "END";   break;
                case ESC "[5~":  me["sChar"] = "PAGEUP";break;
                case ESC "[6~":  me["sChar"] = "PAGEDOWN";break;
                case ESC "OP":   me["sChar"] = "F1";    break;
                case ESC "OQ":   me["sChar"] = "F2";    break;
                case ESC "OR":   me["sChar"] = "F3";    break;
                case ESC "OS":   me["sChar"] = "F4";    break;
                case ESC "m":    me["sChar"] = "F5";    break;
                case ESC "[17~": me["sChar"] = "F6";    break;
                case ESC "[18~": me["sChar"] = "F7";    break;
                case ESC "[19~": me["sChar"] = "F8";    break;
                case ESC "[20~": me["sChar"] = "F9";    break;
                case ESC "[21~": me["sChar"] = "F10";   break;
                case ESC "[23~": me["sChar"] = "F11";   break;
                case ESC "[24~": me["sChar"] = "F12";   break;
                default:
                        if (sizeof(chars[i])==1 &&
                            0<chars[i][0] && chars[i][0]<27)
                                switch (chars[i][0])
                                { // �N�����X�A�Ϧb��J�Ҧ��]��ϥΫ��O
                                case  1: me["sChar"]="Ctrl-A"; break;
                                case  2: me["sChar"]="Ctrl-B"; break;
                                case  4: me["sChar"]="Ctrl-D"; break;
                                case  6: me["sChar"]="Ctrl-F"; break;
                                case  7: me["sChar"]="Ctrl-G"; break;
                                case 10: me["sChar"]="Ctrl-J"; break;
                                case 11: me["sChar"]="Ctrl-K"; break;
                                case 12: me["sChar"]="Ctrl-L"; break;
                                case 14: me["sChar"]="Ctrl-N"; break;
                                case 15: me["sChar"]="Ctrl-O"; break;
                                case 16: me["sChar"]="Ctrl-P"; break;
                                case 17: me["sChar"]="Ctrl-Q"; break;
                                case 18: me["sChar"]="Ctrl-R"; break;
                                case 19: me["sChar"]="Ctrl-S"; break;
                                case 20: me["sChar"]="Ctrl-T"; break;
                                case 21: me["sChar"]="Ctrl-U"; break;
                                case 22: me["sChar"]="Ctrl-V"; break;
                                case 23: me["sChar"]="Ctrl-W"; break;
                                case 24: me["sChar"]="Ctrl-X"; break;
                                case 25: me["sChar"]="Ctrl-Y"; break;
                                case 26: me["sChar"]="Ctrl-Z"; break;
                        } // switch
                        else
                        {
                                me["sChar"] = chars[i];            // �������q�r��
                                if (!bs) me["is_Substituted"] = 0; // �M���N����
                        } // else
                } // switch
                // �N�ഫ�᪺�r��e��������O�禡�B�z�A�}����Ū���U�ӿ�J
                if (_dispatcher(pl) && i==size-1) get_char("_input", HIDE, pl);
        } // for
} // input()


protected int _dispatcher(object pl)                // �������O�줣�P�禡
{
        int  i, count=1;
        mapping me=pl->query_temp("me");


        if ( me["is_Command_Mode"] ||
            (me["is_Substituted"] && // ����J�Ҧ��]��ϥάY�ǫ��O
             // �o�G�ӫ��O���b�o�B�z
             me["sChar"]!="ENTER" && me["sChar"]!="TAB") )
        {        // �{�b�O�R�O�Ҧ�
                if (sizeof(me["sChar"])!=1 && !me["is_Substituted"])
                        return 1;
                // �ˬd�\����w�q��Ӫ�A���s�w�q�R�O
                if (!undefinedp(me["keymap"][me["sChar"]]))
                        me["sChar"] =
                        me["keymap"][me["sChar"]];
                if (!stringp(me["sChar"])) return 1; // Type checking...
                // �ˬd�O�Ʀr���ܡA�N�O���[��R�O�p�ƨ�
                if ('0'<=me["sChar"][0] && me["sChar"][0]<='9')
                        me["sCount"] += me["sChar"];
                else
                {
                        sscanf(me["sCount"], "%d", count);
                        me["sCount"] = ""; // �p�ƾ��k�s
                        // ���ФW�ӫ��O
                        if (me["sChar"] == ".")
                                me["sChar"] = me["sOldChar"];
                        else        // �O���o�������O
                                me["sOldChar"] = me["sChar"];
                }

                for (i=0; i<count; i++)
                        switch (me["sChar"]) // �������O�줣�P�禡
                        {
                        case "a":_append(pl);                           break;
                        case "d":
                        case "Ctrl-D": _del_line(pl);                  break;
                        case "f":
                        case "Ctrl-Z": _refresh(pl);                break;
                        case "g":
                        case "Ctrl-G": _goto_line(pl);                break;
                        case "h":
                        case "LEFT":
                        case "Ctrl-J": _left(pl);                   break;
                        case "i":      _insert(pl);                break;
                        case "j":
                        case "DOWN":
                        case "Ctrl-K": _down(pl);                break;
                        case "k":
                        case "UP":
                        case "Ctrl-O": _up(pl);                        break;
                        case "l":
                        case "RIGHT":
                        case "Ctrl-L": _right(pl, 1,
                                                (me["is_Command_Mode"]?0:1));
                                       break;
                        case "m": _keymap(pl);                        break;
                        case "n":
                        case "Ctrl-N": _next_match(pl);                break;
                        case "o": _append_line(pl);                    break;
                        case "q":        // ��ܤ��AŪ���s��J�A�����s��
                        case "F4":
                        case "Ctrl-Q": _quit(0, pl);                return 0;
                        case "r":
                        case "Ctrl-R": _replace(pl);                break;
                        case "s":
                        case "Ctrl-S": _search(pl);                   break;
                        case "u": _undef_key(pl);                break;
                        case "w":
                        case "F2":
                        case "Ctrl-W": _write(pl);                      break;
                        case "x":
                        case "DELETE":
                        case "Ctrl-X":   _del_char(pl, 0);        break;
                        case "A":
                        case "HOME":
                        case "Ctrl-A":   _home(pl);        break;
                        case "B":
                        case "PAGEUP":
                        case "Ctrl-B":   _page_up(pl);        break;
                        case "E":
                        case "END":
                        case "Ctrl-E":   _end(pl);        break;
                        case "F":
                        case "PAGEDOWN":
                        case "Ctrl-F":   _page_down(pl);        break;
                        case "J":
                        case "Ctrl-P": _join(pl);         break;
                        case "O": _insert_line(pl);         break;
                        case "U":
                        case "Ctrl-U": _file_head(pl);        break;
                        case "V":
                        case "Ctrl-V": _file_end(pl);        break;
                        case "?":
                        case "F1":
                        case "Ctrl-Y": _help(pl);         break;
                        case "~":
                        case "Ctrl-T": _insert_exclam_mark(pl);        break;
                        case "BACKSPACE": _backspace(pl);          break;
                        case "ESC": _esc(pl);                         break;
                        case "TAB": _tab(pl);                        break;
                        } // switch
        } // if me["is_Command_Mode"]
        else
                _process(pl);                // �B�z��J�Ҧ����r���J

        return 1;                        // ����~��Ū���s��J�A�~��s��
} // dispatcher()


protected void _append(object pl)                // �b��Ы᭱�[�r
{
        mapping me=pl->query_temp("me");

        if (sizeof(me["sText"]) == 0) return;
        me["is_Command_Mode"] = 0;
        _refresh_status(pl);
        _right(pl, 1, 1);
} // _append()


protected void _append_line(object pl)        // �b��Щ��U�[�@�s��
{
        string *text;
        mapping me=pl->query_temp("me");

        me["is_Command_Mode"] = me["is_NewFile"] = 0;
        me["is_Modify"] = 1;
        text = me["sText"][0..me["iS_Row"]+me["iRow"]-2] + ({ "" }) +
                me["sText"][me["iS_Row"]+me["iRow"]-1..<1];
        me["sText"] = text;
        _refresh_screen(pl, me["iS_Row"], sizeof(me["sText"]), 1);
        me["iCol"] = 1;
        _down(pl);
} // _append_line()


protected void _backspace(object pl)        // �R����Ыe���r
{
        mapping me=pl->query_temp("me");

        if (me["iS_Col"] == me["iCol"])        return;
        _left(pl);
        _del_char(pl, 1);
} // _backspace()


protected void _confirm_save(string str, object pl) // ���}�s�边�e�T�{�s��
{
        mapping me=pl->query_temp("me");

        if (str=="y" || str=="Y") return _write_done("", pl, 1);
        me["is_Modify"] = 0;                // �]�w�u���ק�v�X��
        _quit(0, pl);
} // _confirm_save()


protected void _del_char(object pl, int bs)                // �R����ФW���r
{
        int    go_left=0;                // �O�_�b�R����n�������
        string str;
        mapping me=pl->query_temp("me");


        if (sizeof(me["sText"])==0 ||
            sizeof(me["sText"][me["iS_Row"]+me["iRow"]-2])==0)
             return;
        if (me["is_NewFile"] || !me["is_Modify"])
        {
                me["is_NewFile"] = 0;
                me["is_Modify"] = 1;
                _refresh_status(pl);
        }
        if (me["iS_Col"]+me["iCol"]-2 >=
            sizeof(me["sText"][me["iS_Row"]+me["iRow"]-2]))
                return;
        str = me["sText"][me["iS_Row"]+me["iRow"]-2][0..me["iS_Col"]+
                me["iCol"]-3];
        // �ˬd�O�_�ݭn���[�ѤU�����e
        if (me["iS_Col"]+me["iCol"]-1 <
            sizeof(me["sText"][me["iS_Row"]+me["iRow"]-2]))
                str += me["sText"][me["iS_Row"]+
                me["iRow"]-2][me["iS_Col"]+me["iCol"]-1..<1];
        else        go_left = 1;                // �]���O�R��������r�A�ҥH�n�� 
	me["sText"][me["iS_Row"]+me["iRow"]-2] = str;
        printf(ESC "[%d;1f%-80s", me["iRow"]+1,        me["sText"][me["iS_Row"]+
                me["iRow"]-2][me["iS_Col"]-1..me["iE_Col"]-1]);
        if (go_left && !bs) _left(pl);
        else        _refresh_cursor(pl);
} // _del_char()


protected void _del_line(object pl)        // �R�����
{
        string *text=({ });
        mapping me=pl->query_temp("me");
        me["is_NewFile"] = 0;
        me["is_Modify"] = 1;
        if (me["iS_Row"]+me["iRow"]-2 > 0)
                text = me["sText"][0..me["iS_Row"]+me["iRow"]-3];
        text += me["sText"][me["iS_Row"]+me["iRow"]-1..<1];
        me["sText"] = text;
        _refresh_screen(pl, me["iS_Row"], me["iE_Row"], me["iS_Col"]);
        if (me["iS_Row"]+me["iRow"]-1 > sizeof(me["sText"]))
                _up(pl);                // �Y�O�R���̫�@��A�N�n�W�����
        // �Y��Ъ��s��m�W�L����A�h���ʴ�Ш���
        else if (me["iS_Col"]+me["iCol"]-1 >
            sizeof(me["sText"][me["iS_Row"]+me["iRow"]-2]))
            _end(pl);
} // _del_line()


protected void _down(object pl)                // ��Щ��U���@��
{
        int  acc;
        mapping me=pl->query_temp("me");


        // �ˬd�O�_�w�b�ɧ�
        if (me["iS_Row"]+me["iRow"]-1 >= sizeof(me["sText"]))
                // �Y�w����ɧ��U�@��A�h������
                if (me["iRow"] < 23) return;
                else
                {        // �h����ɧ��U�@��A�H�����ɧ����s�b
                        me["iS_Row"]++;
                        printf(ESC "[24;1f\r\n~");
                        me["iRow"] = 22;
                }
        else if (++me["iRow"] > 23)
        {        // �e���W���A��ܤU�@��
                me["iS_Row"]++;                me["iE_Row"]++;
                printf(ESC "[24;1f\r\n%s", me["sText"][me["iE_Row"]-1]
                        [me["iS_Col"]-1..me["iE_Col"]-1]);
                me["iRow"] = 23;
        }

        // �Y��Ъ��s��m�W�L����A�h���ʴ�Ш���
        if (me["iS_Col"]+me["iCol"]-1 >
            sizeof(me["sText"][me["iS_Row"]+me["iRow"]-2]))
                me["iCol"] = sizeof(me["sText"][me["iS_Row"]+me["iRow"]-2])-
                        me["iS_Col"]+(me["is_Command_Mode"]?1:2);
        // �Y����L�r�A�h�w��b�Ĥ@��
        if (me["iCol"]==0 && me["iS_Col"]==1) me["iCol"] = 1;
        if (me["iCol"] > 0)_refresh_status(pl);
        else
        {        // ��Ъ��s��m�b��e���~�A�ݭn��ø�e��
                acc = me["iCol"];        me["iCol"] = 1;
                _refresh_screen(pl, me["iS_Row"], me["iE_Row"],
                        me["iS_Col"]+acc-1);
        }
} // _down()


protected void _end(object pl)                // �N��в�����
{
        mapping me=pl->query_temp("me");

        if (sizeof(me["sText"]) == 0) return;
        // �p��������m
        me["iCol"] = sizeof(me["sText"][me["iS_Row"]+me["iRow"]-2])-
                me["iS_Col"]+(me["is_Command_Mode"]?1:2);
        if (me["iCol"] == 0) me["iCol"] = 1; // �Y����L�r�A�h�w��b�Ĥ@��
        if (sizeof(me["sText"][me["iS_Row"]+me["iRow"]-2]) < me["iE_Col"])
                    _refresh_status(pl);
        else
        {        // ��Ъ��s��m�b��e���~�A�ݭn��ø�e��
                me["iCol"] = 79;
                _refresh_screen(pl, me["iS_Row"], me["iE_Row"], me["iS_Col"]+
                        (sizeof(me["sText"][me["iS_Row"]+me["iRow"]-2])-
                        me["iE_Col"]+1));
        }
} // _end()


protected void _esc(object pl)                // �q��J�Ҧ��^��R�O�Ҧ�
{
        mapping me=pl->query_temp("me");
        me["is_Command_Mode"] = 1;
        _left(pl);
} // _esc()


protected void _file_end(object pl)        // �N��в����ɧ�
{
        mapping me=pl->query_temp("me");
        if (sizeof(me["sText"]) == 0) return;
        _goto_line_done(sprintf("%d", sizeof(me["sText"])), pl, 0);
} // _file_end()


protected void _file_head(object pl)        // �N��в������Y
{
        mapping me=pl->query_temp("me");
        if (sizeof(me["sText"]) == 0) return;
        _goto_line_done("1", pl, 0);
} // _file_head()


protected void _goto_line(object pl)        // ����S�w��h
{
        mapping me=pl->query_temp("me");
        _message(pl, sprintf("�п�J�渹�]������ ENTER �����A1~%d)�G",
                sizeof(me["sText"])), "_goto_line_done", ECHO, 1);
} // _goto_line()


protected void _goto_line_done(string str, object pl, int rein) // ���o�渹
{
        int        no;
        mapping me=pl->query_temp("me");

        if (str == "") return _message_done("", pl);
        if (sscanf(str, "%d", no)!=1 || no<1 || no>sizeof(me["sText"]))
                return _message(pl, "���~���渹�I", "_message_done", HIDE);

        me["iCol"] = 1;
        if (me["iS_Row"]<=no && no<=me["iE_Row"])
        {        // ���w�渹�b��i���S��
                me["iRow"] = no-me["iS_Row"]+1;
                _refresh_status(pl);
        }
        else
        {        // ���w�渹���b��i���S�򤤡A�ݭn��ø�e��
                me["iS_Row"] = no-11;
                if (me["iS_Row"] < 1)        me["iS_Row"] = 1;
                if (me["iE_Row"] < no+11)        me["iE_Row"] = no+11;
                me["iRow"] = no-me["iS_Row"]+1;
                _refresh_screen(pl, me["iS_Row"], me["iE_Row"], 1);
        }
        if (rein) get_char("_input", HIDE, pl); // �ˬd�O�_�ݭnŪ���U����J
} // _goto_line_done()


protected void _help(object pl)                // ���U�e��
{
        printf(REF +
"�i LPMud ���ù��s�边 �j1.3 �� 3/25/1998  by �±R��(Kenny Hsieh), ���v�Ҧ�.\r
\r
a            �b��Ы᭱�[�r               d  Ctrl-D    �R�����\r
f  Ctrl-Z    ��s�e��                     g  Ctrl-G    ����S�w��h\r
h  Ctrl-J    ��Щ������@�r               i            �b��Ыe�����r\r
j  Ctrl-K    ��Щ��U���@��               k  Ctrl-O    ��Щ��W���@��\r
l  Ctrl-L    ��Щ��k���@�r               m            �w�q�s�\\����\r
n  Ctrl-N    �j�M/�����U�ӲŦX�r��        o            �b��Щ��U�[�@�s��\r
q  Ctrl-Q    ���}�s�边                   r  Ctrl-R    �r�����\r
s  Ctrl-S    �r��j�M                     u            �����Y�\\����w�q\r
w  Ctrl-W    �x�s�ɮ�                     x  Ctrl-X    �R����ФW���r\r
A  Ctrl-A    �N��в���歺               B  Ctrl-B    ���W���@���]22 ��^\r
E  Ctrl-E    �N��в�����               F  Ctrl-F    ���U���@���]22 ��^\r
J  Ctrl-P    �N�U���r���즹��᭱       O            �b��ФW��[�@�s��\r
U  Ctrl-U    �N��в������Y               V  Ctrl-V    �N��в����ɧ�\r\n");
        printf(
".            ���ФW�ӫ��O                 ?  Ctrl-Y    ���U�e���]���e���^\r
~  Ctrl-T    �b��Ыe�����J�@�ӡu!�v�r��\r\n
�X�k���w�q��O�i�L�r���M ESC�BF1��F12�BBACKSPACE�BTAB�BENTER�BINSERT�BDELETE�B\r
HOME�BEND�BPAGEUP�BPAGEDOWN�BUP�BDOWN�BLEFT�BRIGHT�BCtrl-A��Ctrl-Z�C\r
\r
�w��Ǽ����s�边�A���ЫO�d���v�ŧi�A��������D�M��ĳ���p���ڡG\r
kenny@cindy.cis.nctu.edu.tw�C\r
                                                           [�����N��^��s�边]"
);
        get_char("_input", HIDE, pl, REFRESH); // Ū������H��ø�e��
} // _help()


protected void _home(object pl)                // �N��в���歺
{
        mapping me=pl->query_temp("me");

        me["iCol"] = 1;
        if (me["iS_Col"] == 1)_refresh_status(pl);
        else        _refresh_screen(pl, me["iS_Row"], me["iE_Row"], 1);
} // _home()


protected void _insert(object pl)                // �b��Ыe�����r
{
        mapping me=pl->query_temp("me");

        if (sizeof(me["sText"]) == 0) return;
        me["is_Command_Mode"] = 0;
        _refresh_status(pl);
} // _insert()


protected void _insert_line(object pl)        // �b��ФW��[�@�s��
{
        string *text=({ });
        mapping me=pl->query_temp("me");

        me["is_Command_Mode"] = me["is_NewFile"] = 0;
        me["is_Modify"] = 1;
        // �ˬd�O�_��ФW��O�_�����e
        if (me["iS_Row"]+me["iRow"]-3 >= 0)
                text = me["sText"][0..me["iS_Row"]+me["iRow"]-3];
        text += ({ "" });
        text += me["sText"][me["iS_Row"]+me["iRow"]-2..<1];
        me["sText"] = text;
        me["iCol"] = 1;
        _refresh_screen(pl, me["iS_Row"], sizeof(me["sText"]), 1);
} // _insert_line()


protected void _insert_exclam_mark(object pl) // �b��Ыe�����J�@�ӡu!�v�r��
{
        mapping me=pl->query_temp("me");

        // �]���L�k���`��J�u!�v�A�ҥH�S�a�[���禡�H��J�u!�v�C
        if (sizeof(me["sText"]) == 0) return;
        me["sChar"] = "!";
        _process(pl);
} // _insert_!()


protected void _join(object pl)                // �N�U���r���즹��᭱
{
        string *text=({ });
        mapping me=pl->query_temp("me");


        if (me["iS_Row"]+me["iRow"]-1 >= sizeof(me["sText"])) return;

        me["is_NewFile"] = 0;
        me["is_Modify"] = 1;
        _end(pl);                        // ���N��в�����
        text = me["sText"][0..me["iS_Row"]+me["iRow"]-2];
        if (sizeof(me["sText"][me["iS_Row"]+me["iRow"]-1]))
        {        // �Y�U�榳���e���[�W��
                text[me["iS_Row"]+me["iRow"]-2] += (" "+
                        me["sText"][me["iS_Row"]+me["iRow"]-1]);
                _right(pl, 1, 1);
        }
        text += me["sText"][me["iS_Row"]+me["iRow"]..<1];
        me["sText"] = text;
        _refresh_screen(pl, me["iS_Row"], me["iE_Row"], me["iS_Col"]);
} // _join()


protected void _keymap(object pl)                // �w�q�s�\����
{
        _message(pl, "�п�J�s�w�q��M��\\����]������ ENTER �����A�H�ťչj�}�^",
                "_keymap_done", ECHO);
} // _keymap()


protected void _keymap_done(string str, object pl) // ���o�w�q�\����
{
        string old, _new;
        mapping me=pl->query_temp("me");

        _refresh_status(pl);
        if (str != "")
        {        // �Y����ƿ�J
                if (sscanf(str, "%s %s", _new, old) != 2)
                        return _message(pl, "��J�榡���~�C", "_message_done",
                                HIDE);
                me["keymap"][_new] = old;
                _message(pl, sprintf("�n�F�A�q���H��s�w�q��u%s�v�N����\\����?
?s�v���\\��F�I",
                        _new, old), "_message_done", HIDE);
        }
        else        get_char("_input", HIDE, pl); // ������J�A�~��Ū���U�ӿ�J
} // _keymap_done()


protected void _left(object pl)                // ��Щ������@�r
{
        mapping me=pl->query_temp("me");

        if (me["iS_Col"]==1 && me["iCol"]==1) return _refresh_status(pl);
        if (--me["iCol"] < 1)
        {        // ��Ъ��s��m�b��e���~�A�ݭn��ø�e��
                // �Y���� 8 ��Ӧh���ܡA�N�u�����@��
                if (me["iS_Col"]-8 < 1)
                        me["iCol"] = me["iS_Col"]-1;
                else        me["iCol"] = 8; // ���M�N�]�w��Цb�� 8 ���m
                _refresh_screen(pl, me["iS_Row"], me["iE_Row"],
                        me["iS_Col"]-me["iCol"]);
                return;
        }
        _refresh_status(pl);
} // _left()


// �b���A�C��ܰT��
protected varargs void _message(object pl, string str, string callback, int hide,
mixed arg)
{
        printf(HOME + NOR + REV);        // ���ʴ�Ш� (1,1)�A�]�w�Ϭۦr�����
        // �M���쪬�A�C���T��
        printf("
                ");
        printf(HOME + str);                // ���ʴ�Ш� (1,1)�A�A��ܰT��
        input_to(callback, hide, pl, arg); // Ū����J���
} // _message()


protected void _message_done(string str, object pl) // �����T�������
{
        _refresh_status(pl);
        get_char("_input", HIDE, pl);        // �~��Ū����J�r��
} // _message_done()


protected void _next_match(object pl)                // �j�M/�����U�ӲŦX�r��
{
        mapping me=pl->query_temp("me");
        string str="";
        // �]�w�_�l�j�M��m����в{�b��m
        int    j=me["iS_Col"]+me["iCol"]-1,
               i, ofs;


        if (!stringp(me["sSearch"])) return; // �Y�S���]�w�j�M�r��A������

        for (i=me["iS_Row"]+me["iRow"]-2; i<sizeof(me["sText"]); i++)
        {
                if ((ofs = strsrch(me["sText"][i][j-1..<1], me["sSearch"]))== -1)
                        j = 1; // �o��S��쪺�ܡA�]�w�U��q�Ĥ@��}�l��
                else
                {        // �����w�r��F, ���ʴ�Ш�ت���
                        _goto_line_done(sprintf("%d", i+1), pl, 0);
                        me["iCol"] = j+ofs; // �p����w�r�ꪺ�����m
                        // �Y���w�r�긨�b��e���~�A�h��ø�e��
                        if (me["iCol"]<me["iS_Col"] ||
                            me["iCol"]+strlen(me["sSearch"])>me["iS_Col"]+79)
                                _refresh_screen(pl, me["iS_Row"], me["iE_Row"],
                                        me["iCol"]);
                        if (stringp(me["sReplace"]))
                        {        // �ݭn�����r��
                                me["is_NewFile"] = 0;
                                me["is_Modify"] = 1;
                                // ���[��Ыe���e
                                str = me["sText"][i][0..me["iCol"]-2];
                                str += me["sReplace"];
                                str += (me["sText"][i][me["iCol"]+
                                        strlen(me["sSearch"])-1..<1]);
                                me["sText"][i] = str;
                                // �Y�����r�긨�b��e���~�A�h��ø�e��
                                if (me["iCol"]<me["iS_Col"] ||
                                    me["iCol"]+strlen(me["sReplace"])
                                    > me["iS_Col"]+79)
                                        _refresh_screen(pl, me["iS_Row"],
                                                me["iE_Row"], me["iCol"]);
                                // �N��}��������r��᭱
                                me["iCol"] = me["iCol"]+strlen(me["sReplace"])-
                                        me["iS_Col"]+1;
                                printf(ESC "[%d;1f%-80s", me["iRow"]+1,
                                        me["sText"][me["iS_Row"]+
                                        me["iRow"]-2][me["iS_Col"]-1
                                        ..me["iE_Col"]-1]);
                        }
                        // �N��}����j�M�r��᭱
                        else        
				me["iCol"] = me["iCol"]+strlen(me["sSearch"])-me["iS_Col"]+1;
                        _refresh_status(pl);
                        break;
                } // if found
        } // for each row
        if (i >= sizeof(me["sText"]))
                _message(pl, "�䤣����w�r��I", "_message_done", HIDE);
        else        get_char("_input", HIDE, pl); // Ū���U�ӿ�J�r��
} // _next_match()


protected void _page_down(object pl)        // ���U���@���]22 ��^
{
        mapping me=pl->query_temp("me");

        if (me["iS_Row"]+22 > sizeof(me["sText"])) return; // �ˬd�O�_����A���F
        me["iS_Row"] += 22;        me["iE_Row"] += 22;
        // �ˬd��Ъ��s��m�O�_�W�L�ɧ�
        if (me["iS_Row"]+me["iRow"]-1 > sizeof(me["sText"]))
                me["iRow"] = sizeof(me["sText"])-me["iS_Row"]+1;
        _refresh_screen(pl, me["iS_Row"], me["iE_Row"], me["iS_Col"]);
        // �Y��Ъ��s��m�W�L����A�h���ʴ�Ш���
        if (me["iS_Col"]+me["iCol"]-1 > sizeof(me["sText"][me["iS_Row"]+
                me["iRow"]-2]))
                _end(pl);
} // _page_down()


protected void _page_up(object pl)        // ���W���@���]22 ��^
{
        mapping me=pl->query_temp("me");

        if (me["iS_Row"] <= 1) return; // �ˬd�O�_����A���F
        me["iS_Row"] -= 22;
        if (me["iS_Row"] < 1) me["iS_Row"] = 1; // �̦h�u��½��Ĥ@�C
        _refresh_screen(pl, me["iS_Row"], me["iE_Row"], me["iS_Col"]);
        // �Y��Ъ��s��m�W�L����A�h���ʴ�Ш���
        if (me["iS_Col"]+me["iCol"]-1 >
            sizeof(me["sText"][me["iS_Row"]+me["iRow"]-2]))
            _end(pl);
} // _page_up()


protected void _process(object pl)        // �B�z��J�Ҧ����r���J
{
        int    i, size;
        string str, rest, *input;
        mapping me=pl->query_temp("me");


        if (me["is_Modify"]==0 || me["is_NewFile"]==1)
        {
                me["is_NewFile"] = 0;
                me["is_Modify"] = 1;
                _refresh_status(pl);
        }
        if (!me["is_Substituted"] && (strsrch(me["sChar"], "\r")!=-1 ||
            strsrch(me["sChar"], "\n")!=-1))
                me["is_Substituted"] = 1; // �]�w���X�N���X��
        me["sChar"] = replace_string(me["sChar"], "\t", "        ");
        me["sChar"] = replace_string(me["sChar"], "\r", "\rENTER\r");
        me["sChar"] = replace_string(me["sChar"], "\n", "\rENTER\r");
        input = explode(me["sChar"], "\r");

        size = sizeof(input);
        for (i=0; i<size; i++)                // �@���B�z�@���J
        {
                if (me["is_Substituted"] && input[i] == "ENTER")
                {        // ����J ENTER �ɡA�n�N��Ф��᪺���e����U�����s��
                        rest = me["sText"][me["iS_Row"]+
                                me["iRow"]-2][me["iS_Col"]+me["iCol"]-2..<1];
                        me["sText"][me["iS_Row"]+me["iRow"]-2] =
                                me["sText"][me["iS_Row"]+
                                me["iRow"]-2][0..me["iS_Col"]+me["iCol"]-3];
                        _append_line(pl); // �b��Щ��U�[�@�s��
                        // �s�檺���e�O���Ц�m�H�᪺���e
                        me["sText"][me["iS_Row"]+me["iRow"]-2] = rest;
                        continue;
                }

                // ��J�r�ꤣ�O ENTER ��, �B�z TAB ���w��
                if (me["is_Substituted"] && input[i] == "TAB")
                        input[i] = "        "[0..7-(me["iCol"]-1)%8];
                str = me["sText"][me["iS_Row"]+me["iRow"]-2][0..me["iS_Col"]+
                        me["iCol"]-3] + input[i] + me["sText"][me["iS_Row"] +
                        me["iRow"]-2][me["iS_Col"]+ me["iCol"]-2..<1];
                me["sText"][me["iS_Row"]+me["iRow"]-2] = str;
                _right(pl, sizeof(input[i]), 1);
        } // for

        printf(ESC "[%d;1f%s", me["iRow"]+1, me["sText"][me["iS_Row"]+
                me["iRow"]-2][me["iS_Col"]-1..me["iE_Col"]-1]);
        _refresh_cursor(pl);
} // _process()


protected void _quit(mixed unused, mixed pl) // ���}�s�边
{
        mapping me;

        seteuid(geteuid(pl));
        me = pl->query_temp("me");
        if (me["is_Modify"])
                return _message(pl, "���ɮפw���A�аݻݭn�s�ɶܡ]y/n)�H[n]",
                        "_confirm_save", ECHO);
        me["iRow"] = 23;
        _refresh_cursor(pl);                // ���ʴ�Ш�̫�@��
        printf(NOR "\r\n");
        // �Y�\����w�q��Ӫ�O�Ū��A�N�M�����a���W���O���A���M�N�O���b���a���W
        if (sizeof(me["keymap"]) == 0) pl->delete("me_keymap");
        else pl->set("me_keymap", me["keymap"]);
        map_delete(EditedFiles, pl->query_temp("me/sFileName"));
        pl->delete_temp("me"); // �M���s�边�Ψ쪺�Ȯ��ܼ�
} // _quit()


protected void _refresh(object pl)        // ��s�e��
{
        mapping me=pl->query_temp("me");
        _refresh_screen(pl, me["iS_Row"], me["iE_Row"], me["iS_Col"]);
} // _refresh()


protected void _replace(object pl)        // �r�����
{
        _message(pl, "�j�M/�����r��(������ENTER����,�H�ťչj�}):",
                "_replace_done", ECHO);
} // _replace()

protected void _replace_done(string str, object pl) // ���o�����r��
{
        mapping me=pl->query_temp("me");

        _refresh_status(pl);
        if (str != "")
        {        // ����J��Ʈ�
                if (sscanf(str, "%s %s", me["sSearch"],        me["sReplace"]) != 2)
                {        // �u���@�Ӧr��A�N���w���j�M�r��A�N�Y�������w�r��
                        me["sSearch"] = str;
                        me["sReplace"] = "";
                }
                _next_match(pl);
        }
        else        get_char("_input", HIDE, pl); // �~��Ū���U�ӿ�J�r��
} // _replace_done()


protected void _right(object pl, int col, int extra)        // ��Щ��k���@�r
{
        int    acc;
        mapping me=pl->query_temp("me");


        if (sizeof(me["sText"])==0 || me["iS_Col"]+me["iCol"]-1>
            sizeof(me["sText"][me["iS_Row"]+me["iRow"]-2])-1+extra)
            return;
        me["iCol"] += col;
        if (me["iS_Col"]+me["iCol"]-1 > sizeof(me["sText"][me["iS_Row"]+
            me["iRow"]-2])+extra)
                me["iCol"] = sizeof(me["sText"][me["iS_Row"]+me["iRow"]-2])-
                        me["iS_Col"]+1+extra;
        if (me["iCol"] > 80)
        {        // ��Ъ��s��m���b�i���������A�ݭn���k���ʵ���
                // �Y�k�� 8 ��Ӧh���ܡA�N�u�k������
                if (me["iE_Col"]+8 > sizeof(me["sText"][me["iS_Row"]+
                    me["iRow"]-2])+1)
                        acc = sizeof(me["sText"][me["iS_Row"]+me["iRow"]-2])-
                                me["iE_Col"]+1;
                else        acc = 8;
                me["iCol"] = 80-acc+1;         // �p���Ъ��s��m
                _refresh_screen(pl, me["iS_Row"], me["iE_Row"], me["iS_Col"]+acc);
                return;
        }
        _refresh_status(pl);
} // _right()


protected void _search(object pl)                // �r��j�M
{
        _message(pl, "�п�J�j�M�r��]������ ENTER ����)�G", "_search_done",
                ECHO);
} // _search()


protected void _search_done(string str, object pl) // ���o�j�M�r��
{
        mapping me=pl->query_temp("me");

        _refresh_status(pl);
        if (str != "")
        {        // ����J��Ʈ�
                me["sSearch"] = str;        me["sReplace"] = 0;
                _next_match(pl);
        }
        else        get_char("_input", HIDE, pl); // �~��Ū���U�ӿ�J�r��
} // _search_done()


protected void _tab(object pl)                 // �R�O�Ҧ��U TAB �䪺�w��
{
        mapping me=pl->query_temp("me");
        _right(pl, 8-(me["iCol"]-1)%8, 0);
} // _tab()


protected void _undef_key(object pl)        // �����Y�\����w�q
{
        _message(pl, "�п�J�������w�q���\\����]������ ENTER ����)�G",
                "_undef_key_done", ECHO);
} // undef_key()


protected void _undef_key_done(string str, object pl) // ���o���w�\����
{
        mapping me=pl->query_temp("me");
        if (str != "")        map_delete(me["keymap"], str);
        _message_done("", pl);
} // undef_key_done()


protected void _up(object pl)                // ��Щ��W���@��
{
        int  acc;
        mapping me=pl->query_temp("me");


        if (me["iRow"]==1 && me["iS_Row"]==1)        return;
        if (--me["iRow"] < 1)
        {        // ��зs��m���b�i���������A�N�W������
                me["iS_Row"]--;
                me["iE_Row"]=me["iS_Row"]+22;
                _refresh_screen(pl, me["iS_Row"], me["iE_Row"], me["iS_Col"]);
                me["iRow"] = 1;
        }
        // �Y��зs��m�W�L����A�h������
        if (me["iS_Col"]+me["iCol"]-1 > sizeof(me["sText"][me["iS_Row"]+
            me["iRow"]-2]))
                me["iCol"] = sizeof(me["sText"][me["iS_Row"]+me["iRow"]-2])-
                        me["iS_Col"]+(me["is_Command_Mode"]?1:2);
        // �Y����L�r�A�h�w��b�Ĥ@��
        if (me["iCol"]==0 && me["iS_Col"]==1) me["iCol"] = 1;
        if (me["iCol"] > 0) _refresh_status(pl);
        else
        {        // ��зs��m���b�i���������A��ø�e��
                acc = me["iCol"];        me["iCol"] = 1;
                _refresh_screen(pl, me["iS_Row"], me["iE_Row"],
                        me["iS_Col"]+acc-1);
        }
} // _up()


protected void _write(object pl)                // ���o�x�s�ɮצW��
{
        _message(pl, "�п�J�s�ɦW�]������ ENTER �H�ϥ����ɦW)�G",
                "_write_done", ECHO, 0);
} // _write()


protected void _write_done(string str, object pl, int quit) // �x�s�ɮ�
{
        string callback;
        mapping me=pl->query_temp("me");

        if (str == "") str = me["sFileName"];
        else        // ���o�ɦW
                str = resolve_path(pl->query("cwd"), str);
        if (quit) callback = "_quit";
        else callback = "_message_done";
        if (write_file(str, implode(me["sText"], "\n")+"\n", 1))
        {
                if (me["is_Modify"])
                        log_file(LOGFILE, sprintf("[%s] %s %s %s\n",
                                ctime(time()), getuid(pl),
                                me["is_NewFile"]? "+": "*", str));
                me["is_Modify"] = me["is_NewFile"] = 0;
                me["sFileName"] = str;
                _message(pl, "�s�ɦ��\\�C", callback, HIDE);
        }
        else
                _message(pl, "�s�ɥ��ѡC", callback, HIDE);
} // write_done()
