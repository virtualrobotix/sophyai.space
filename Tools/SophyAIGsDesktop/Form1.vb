Public Class MqttBox
    Public Sub New()

        ' La chiamata è richiesta dalla finestra di progettazione.
        InitializeComponent()

        ' Aggiungere le eventuali istruzioni di inizializzazione dopo la chiamata a InitializeComponent().

        MqttUrl.Text = "rp.lasernavigation.it"
        MqttPort.Text = "6016"
        MqttUser.Text = "satellite"
        MqttPassword.Text = ""

        mqtt_tx_topic.Text = "sophyaispace/user0031/GPAP01/cmnd/txB64"
        mqtt_tx_payload.Text = "SGVsbG8gU3BhY2UgISEh"
        MqttTopicRx.Text = "sophyaispace/user0030/console/global_rx"
    End Sub

    Private Sub Label2_Click(sender As Object, e As EventArgs) Handles Label2.Click

    End Sub

    Private Sub Connect_Click(sender As Object, e As EventArgs) Handles Connect.Click
        My.mqtt_connect("sophyAIGS", MqttUrl.Text, MqttPort.Text, MqttUser.Text, MqttPassword.Text)

        Timer1.Enabled = True
    End Sub

    Private Sub TreeView1_AfterSelect(sender As Object, e As TreeViewEventArgs)

    End Sub

    Private Sub ListBox1_SelectedIndexChanged(sender As Object, e As EventArgs)

    End Sub

    Private Sub Timer1_Tick(sender As Object, e As EventArgs) Handles Timer1.Tick
        Static Dim topic As String
        Static Dim payload As String
        Static Dim last_payload
        topic = My.get_last_topic()
        Dim tfine As Double
        tfine = DateAndTime.Timer
        If topic = MqttTopicRx.Text Then
            MqttPayloadRx.Text = My.get_last_payload()
            If MqttPayloadRx.Text <> "" And last_payload <> MqttPayloadRx.Text Then
                last_payload = MqttPayloadRx.Text
                fine.Text = tfine
            End If
        Else
            SatInViewPayload.Text = My.get_last_payload()
        End If
    End Sub

    Private Sub mqtt_disconnect_Click(sender As Object, e As EventArgs) Handles mqtt_disconnect.Click
        My.mqtt_disconect()
    End Sub

    Private Sub TextBox2_TextChanged(sender As Object, e As EventArgs) Handles mqtt_tx_topic.TextChanged

    End Sub

    Private Sub mqtt_Tx_Click(sender As Object, e As EventArgs) Handles mqtt_Tx.Click
        Dim t As Double
        Dim ret = My.Publish(mqtt_tx_topic.Text, mqtt_tx_payload.Text)
        t = DateAndTime.Timer
        inizio.Text = t

    End Sub

    Private Sub MqttBox_Load(sender As Object, e As EventArgs) Handles MyBase.Load

    End Sub

    Private Sub Button1_Click(sender As Object, e As EventArgs) Handles Button1.Click
        Dim ret = My.mqtt_subscribe(MqttTopicRx.Text)
    End Sub

    Private Sub MqttPassword_TextChanged(sender As Object, e As EventArgs) Handles MqttPassword.TextChanged

    End Sub

    Private Sub MqttTopicRx_TextChanged(sender As Object, e As EventArgs) Handles MqttTopicRx.TextChanged

    End Sub

    Private Sub MqttPayloadRx_TextChanged(sender As Object, e As EventArgs) Handles MqttPayloadRx.TextChanged

    End Sub
End Class
