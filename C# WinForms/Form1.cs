using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Data.SQLite;

namespace MP_4._1
{
    public partial class Form1 : Form
    {
        int task1_index = 1;
        string task1_fio;
        SQLiteConnection connect = new SQLiteConnection("Data Source=" + "..\\..\\database.db");
        SQLiteCommand m_sqlCmd = new SQLiteCommand();

        public Form1()
        {
            
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            connect.Open();
            comboBox1.SelectedText = "1";
            comboBox2.SelectedText = "All";
            comboBox3.SelectedText = "Fundamental algoritms";
            SQLiteDataAdapter data_adapter = new SQLiteDataAdapter("select * from Students", connect);
            DataTable dTable = new DataTable();
            //String sqlQuery;

            try
            {
                data_adapter.Fill(dTable);
                dataGridView1.AutoResizeColumns();
            }
            catch (System.Data.SQLite.SQLiteException ex)
            { MessageBox.Show(ex.Message); }
            dataGridView1.DataSource = dTable;
            dataGridView1.AutoResizeColumns();
            /*try
            {
                m_sqlCmd.Connection = connect;

                m_sqlCmd.CommandText = "CREATE TABLE IF NOT EXISTS Catalog (id INTEGER PRIMARY KEY AUTOINCREMENT, fio TEXT, gender TEXT, course INTEGER, groupe INTEGER)";
                m_sqlCmd.ExecuteNonQuery();
                MessageBox.Show("Таблица успешно создана!");
            }
            catch (SQLiteException ex)
            {
                MessageBox.Show("Ошибка: " + ex.Message);
            }*/
        }

        private void Form_Closing(object sender, EventArgs e)
        {
            connect.Close();
        }

        private void button1_Click(object sender, EventArgs e)
        {

            /*try
            {
                m_sqlCmd.CommandText = "INSERT INTO Catalog ('fio', 'gender', 'course', 'groupe') values ('" + "Mila Erase M." + "' , '" + "Female" + "' , '" + 2 + "' , '" + 210  + "')";
                m_sqlCmd.ExecuteNonQuery();
            }
            catch (SQLiteException ex)
            {
                MessageBox.Show("Error: " + ex.Message);
            }*/

            // Формирование SQL-запроса
            SQLiteCommand command = new SQLiteCommand("select fio, gender, course, groupe from Students",
            connect);
            try
            { // Исполнение запроса
                SQLiteDataReader reader = command.ExecuteReader(); // Цикл по всем возвращённым записям из результата запроса
                while (reader.Read())
                    { // Здесь располагаются действия с результатами запроса
                      // Первое поле текущей записи имеет вид reader[0]  3
                      // Второе - reader[1], и т.д.
                    }
            }
            catch (System.Data.SQLite.SQLiteException ex)
            {
                MessageBox.Show(ex.Message);
            }

        }

        private void button2_Click(object sender, EventArgs e)
        {
            SQLiteDataAdapter data_adapter = new SQLiteDataAdapter("select * from Students", connect);
            DataTable dTable = new DataTable();
            //String sqlQuery;

            try
            {
                data_adapter.Fill(dTable);
                dataGridView1.AutoResizeColumns();
            }
            catch (System.Data.SQLite.SQLiteException ex)
            { MessageBox.Show(ex.Message); }
            dataGridView1.DataSource = dTable;
            dataGridView1.AutoResizeColumns();
            
        }
        private void button3_Click(object sender, EventArgs e)
        {
            SQLiteDataAdapter data_adapter = new SQLiteDataAdapter("select * from Dist", connect);
            DataTable dTable = new DataTable();
            //String sqlQuery;

            try
            {
                data_adapter.Fill(dTable);

            }
            catch (System.Data.SQLite.SQLiteException ex)
            { MessageBox.Show(ex.Message); }
            dataGridView1.DataSource = dTable;
            dataGridView1.AutoResizeColumns();
        }

        private void comboBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            task1_index = System.Convert.ToInt32(comboBox1.SelectedItem.ToString());
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {
            task1_fio = textBox1.Text;
        }

        //результаты сдачи заданной сессии выбранным студентом; 
        private void button4_Click(object sender, EventArgs e)
        {
            if (textBox1.Text == "")
            {
                MessageBox.Show("Enter FIO!");
                return;
            }
            string name = textBox1.Text.ToString();
            int sem = System.Convert.ToInt32(comboBox1.Text.ToString());
            string command = "select Students.fio, Dist.Name_, Dist.Mark from Students JOIN Dist ON Students.id=Dist.id where fio = :nam and Dist.Sem = :semm;";


            SQLiteDataAdapter data_adapter1 = new SQLiteDataAdapter(command, connect);
            data_adapter1.SelectCommand.Parameters.Add("nam", DbType.String);
            data_adapter1.SelectCommand.Parameters.Add("semm", DbType.Int32);
            data_adapter1.SelectCommand.Parameters[0].Value = name;
            data_adapter1.SelectCommand.Parameters[1].Value = sem;
            DataTable dTable = new DataTable();

            try
            {
                data_adapter1.Fill(dTable);

            }
            catch (System.Data.SQLite.SQLiteException ex)
            { MessageBox.Show(ex.Message); }
            dataGridView2.DataSource = dTable;
            dataGridView2.AutoResizeColumns();
        }

        private void button7_Click(object sender, EventArgs e)
        {

            switch (comboBox2.Text)
            {
                case "Technecal":

                    {
                        string command = "select Dist.Name_, AVG(Dist.Mark) from Students JOIN Dist ON Students.id=Dist.id where Dist.name_= :val ;";

                        SQLiteDataAdapter data_adapter1 = new SQLiteDataAdapter(command, connect);
                        data_adapter1.SelectCommand.Parameters.Add("val", DbType.String);
                        data_adapter1.SelectCommand.Parameters[0].Value = "Fundamental algoritms";
                        DataTable dTable = new DataTable();

                        try
                        {
                            data_adapter1.Fill(dTable);

                        }
                        catch (System.Data.SQLite.SQLiteException ex)
                        { MessageBox.Show(ex.Message); }
                        dataGridView2.DataSource = dTable;
                        if (comboBox2.Text == "All")
                            dataGridView2.Rows[0].Cells[0].Value = "All";
                        dataGridView2.AutoResizeColumns();
                        break;
                    }
                case "Special":
                    {
                        string command = "select Dist.Name_, AVG(Dist.Mark) from Students JOIN Dist ON Students.id=Dist.id where Dist.name_= :val ;";

                        SQLiteDataAdapter data_adapter1 = new SQLiteDataAdapter(command, connect);
                        data_adapter1.SelectCommand.Parameters.Add("val", DbType.String);
                        data_adapter1.SelectCommand.Parameters[0].Value = "Art and Craft";
                        DataTable dTable = new DataTable();

                        try
                        {
                            data_adapter1.Fill(dTable);

                        }
                        catch (System.Data.SQLite.SQLiteException ex)
                        { MessageBox.Show(ex.Message); }
                        dataGridView2.DataSource = dTable;
                        if (comboBox2.Text == "All")
                            dataGridView2.Rows[0].Cells[0].Value = "All";
                        dataGridView2.AutoResizeColumns();
                        break;
                    }

                case "All":
                    {
                        string command;
                        command = "select Dist.Name_, AVG(Dist.Mark) from Students JOIN Dist ON Students.id=Dist.id;";
                        SQLiteDataAdapter data_adapter1 = new SQLiteDataAdapter(command, connect);
                        DataTable dTable = new DataTable();

                        try
                        {
                            data_adapter1.Fill(dTable);

                        }
                        catch (System.Data.SQLite.SQLiteException ex)
                        { MessageBox.Show(ex.Message); }
                        dataGridView2.DataSource = dTable;
                        if (comboBox2.Text == "All")
                            dataGridView2.Rows[0].Cells[0].Value = "All";
                        dataGridView2.AutoResizeColumns();
                        break;

                    }
            }
        }

        private void button5_Click(object sender, EventArgs e)
        {
            switch (comboBox3.Text)
            {
                case "Fundamental algoritms":
                    {
                        string name = textBox1.Text.ToString();
                        string command = "select Students.fio, Dist.Sem, Dist.Date, Dist.Teacher, Dist.Mark from Students JOIN Dist ON Students.id=Dist.id where Dist.Name_ = :val;";


                        SQLiteDataAdapter data_adapter1 = new SQLiteDataAdapter(command, connect);
                        data_adapter1.SelectCommand.Parameters.Add("val", DbType.String);
                        data_adapter1.SelectCommand.Parameters[0].Value = comboBox3.Text;
                        DataTable dTable = new DataTable();

                        try
                        {
                            data_adapter1.Fill(dTable);

                        }
                        catch (System.Data.SQLite.SQLiteException ex)
                        { MessageBox.Show(ex.Message); }
                        dataGridView2.DataSource = dTable;
                        dataGridView2.AutoResizeColumns();
                        break;
                    }
                case "Art and Craft":
                    {
                        string name = textBox1.Text.ToString();
                        string command = "select Students.fio, Dist.Sem, Dist.Date, Dist.Teacher, Dist.Mark from Students JOIN Dist ON Students.id=Dist.id where Dist.Name_ = :val;";


                        SQLiteDataAdapter data_adapter1 = new SQLiteDataAdapter(command, connect);
                        data_adapter1.SelectCommand.Parameters.Add("val", DbType.String);
                        data_adapter1.SelectCommand.Parameters[0].Value = comboBox3.Text;
                        DataTable dTable = new DataTable();

                        try
                        {
                            data_adapter1.Fill(dTable);

                        }
                        catch (System.Data.SQLite.SQLiteException ex)
                        { MessageBox.Show(ex.Message); }
                        dataGridView2.DataSource = dTable;
                        dataGridView2.AutoResizeColumns();
                        break;
                    }
            }

        }

        private void button6_Click(object sender, EventArgs e)
        {
            if (textBox2.Text == "")
            {
                MessageBox.Show("Enter ID!");
                return;
            }
            int id = 0;
            string fio = textBox2.Text;
            string command = "SELECT id FROM Students where fio = :tor ;";

            SQLiteDataAdapter data_adapter1 = new SQLiteDataAdapter(command, connect);
            data_adapter1.SelectCommand.Parameters.Add("tor", DbType.String);
            data_adapter1.SelectCommand.Parameters[0].Value = fio;
            DataTable dTable = new DataTable();
        
            try
            {
                data_adapter1.Fill(dTable);

            }
            catch (System.Data.SQLite.SQLiteException ex)
            { MessageBox.Show(ex.Message); }
            dataGridView2.DataSource = dTable;
            id = System.Convert.ToInt32(dataGridView2.Rows[0].Cells[0].Value);
            dTable.Clear();


            command = "select Students.fio, Dist.Name_, Dist.Date, Dist.Teacher, Dist.Mark from Students JOIN Dist ON Students.id=Dist.id where Students.id = :val;";


            SQLiteDataAdapter data_adapter2 = new SQLiteDataAdapter(command, connect);
            data_adapter2.SelectCommand.Parameters.Add("val", DbType.String);
            data_adapter2.SelectCommand.Parameters[0].Value = id;
            DataTable dTable1 = new DataTable();

            try
            {
                data_adapter2.Fill(dTable1);

            }
            catch (System.Data.SQLite.SQLiteException ex)
            { MessageBox.Show(ex.Message); }
            dataGridView2.DataSource = dTable1;
            dataGridView2.AutoResizeColumns();
        }


    }
}
