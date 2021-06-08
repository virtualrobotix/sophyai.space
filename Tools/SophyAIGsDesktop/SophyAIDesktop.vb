<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()>
Partial Class MqttBox
    Inherits System.Windows.Forms.Form

    'Form overrides dispose to clean up the component list.
    <System.Diagnostics.DebuggerNonUserCode()>
    Protected Overrides Sub Dispose(ByVal disposing As Boolean)
        Try
            If disposing AndAlso components IsNot Nothing Then
                components.Dispose()
            End If
        Finally
            MyBase.Dispose(disposing)
        End Try
    End Sub

    Friend WithEvents Label10 As Label
    Friend WithEvents StationName As TextBox

    'Required by the Windows Form Designer
    Private components As System.ComponentModel.IContainer

    'NOTE: The following procedure is required by the Windows Form Designer
    'It can be modified using the Windows Form Designer.  
    'Do not modify it using the code editor.
    <System.Diagnostics.DebuggerStepThrough()>
    Private Sub InitializeComponent()
        Me.components = New System.ComponentModel.Container()
        Me.Connect = New System.Windows.Forms.Button()
        Me.MqttUrl = New System.Windows.Forms.TextBox()
        Me.MqttPort = New System.Windows.Forms.TextBox()
        Me.MqttUser = New System.Windows.Forms.TextBox()
        Me.MqttPassword = New System.Windows.Forms.TextBox()
        Me.Label1 = New System.Windows.Forms.Label()
        Me.Label2 = New System.Windows.Forms.Label()
        Me.Label3 = New System.Windows.Forms.Label()
        Me.Label4 = New System.Windows.Forms.Label()
        Me.SatInViewPayload = New System.Windows.Forms.TextBox()
        Me.Timer1 = New System.Windows.Forms.Timer(Me.components)
        Me.mqtt_disconnect = New System.Windows.Forms.Button()
        Me.mqtt_Tx = New System.Windows.Forms.Button()
        Me.Label5 = New System.Windows.Forms.Label()
        Me.mqtt_tx_topic = New System.Windows.Forms.TextBox()
        Me.mqtt_tx_payload = New System.Windows.Forms.TextBox()
        Me.Label6 = New System.Windows.Forms.Label()
        Me.Label7 = New System.Windows.Forms.Label()
        Me.Label8 = New System.Windows.Forms.Label()
        Me.Label9 = New System.Windows.Forms.Label()
        Me.MqttPayloadRx = New System.Windows.Forms.TextBox()
        Me.MqttTopicRx = New System.Windows.Forms.TextBox()
        Me.Button1 = New System.Windows.Forms.Button()
        Me.inizio = New System.Windows.Forms.Label()
        Me.fine = New System.Windows.Forms.Label()
        Me.Label10 = New System.Windows.Forms.Label()
        Me.StationName = New System.Windows.Forms.TextBox()
        Me.SuspendLayout()
        '
        'Connect
        '
        Me.Connect.Location = New System.Drawing.Point(502, 33)
        Me.Connect.Name = "Connect"
        Me.Connect.Size = New System.Drawing.Size(94, 29)
        Me.Connect.TabIndex = 0
        Me.Connect.Text = "Connect"
        Me.Connect.UseVisualStyleBackColor = True
        '
        'MqttUrl
        '
        Me.MqttUrl.Location = New System.Drawing.Point(90, 33)
        Me.MqttUrl.Name = "MqttUrl"
        Me.MqttUrl.Size = New System.Drawing.Size(141, 27)
        Me.MqttUrl.TabIndex = 1
        '
        'MqttPort
        '
        Me.MqttPort.Location = New System.Drawing.Point(353, 34)
        Me.MqttPort.Name = "MqttPort"
        Me.MqttPort.Size = New System.Drawing.Size(125, 27)
        Me.MqttPort.TabIndex = 2
        '
        'MqttUser
        '
        Me.MqttUser.Location = New System.Drawing.Point(106, 86)
        Me.MqttUser.Name = "MqttUser"
        Me.MqttUser.Size = New System.Drawing.Size(125, 27)
        Me.MqttUser.TabIndex = 3
        '
        'MqttPassword
        '
        Me.MqttPassword.Location = New System.Drawing.Point(353, 83)
        Me.MqttPassword.Name = "MqttPassword"
        Me.MqttPassword.PasswordChar = Global.Microsoft.VisualBasic.ChrW(42)
        Me.MqttPassword.Size = New System.Drawing.Size(125, 27)
        Me.MqttPassword.TabIndex = 4
        '
        'Label1
        '
        Me.Label1.AutoSize = True
        Me.Label1.Location = New System.Drawing.Point(24, 37)
        Me.Label1.Name = "Label1"
        Me.Label1.Size = New System.Drawing.Size(60, 20)
        Me.Label1.TabIndex = 5
        Me.Label1.Text = "MqttUrl"
        '
        'Label2
        '
        Me.Label2.AutoSize = True
        Me.Label2.Location = New System.Drawing.Point(241, 33)
        Me.Label2.Name = "Label2"
        Me.Label2.Size = New System.Drawing.Size(71, 20)
        Me.Label2.TabIndex = 6
        Me.Label2.Text = "Mqtt Port"
        '
        'Label3
        '
        Me.Label3.AutoSize = True
        Me.Label3.Location = New System.Drawing.Point(26, 93)
        Me.Label3.Name = "Label3"
        Me.Label3.Size = New System.Drawing.Size(74, 20)
        Me.Label3.TabIndex = 7
        Me.Label3.Text = "Mqtt User"
        '
        'Label4
        '
        Me.Label4.AutoSize = True
        Me.Label4.Location = New System.Drawing.Point(241, 86)
        Me.Label4.Name = "Label4"
        Me.Label4.Size = New System.Drawing.Size(106, 20)
        Me.Label4.TabIndex = 8
        Me.Label4.Text = "Mqtt Password"
        '
        'SatInViewPayload
        '
        Me.SatInViewPayload.Location = New System.Drawing.Point(12, 150)
        Me.SatInViewPayload.Multiline = True
        Me.SatInViewPayload.Name = "SatInViewPayload"
        Me.SatInViewPayload.Size = New System.Drawing.Size(570, 79)
        Me.SatInViewPayload.TabIndex = 9
        '
        'Timer1
        '
        Me.Timer1.Interval = 10
        '
        'mqtt_disconnect
        '
        Me.mqtt_disconnect.Location = New System.Drawing.Point(502, 86)
        Me.mqtt_disconnect.Name = "mqtt_disconnect"
        Me.mqtt_disconnect.Size = New System.Drawing.Size(94, 29)
        Me.mqtt_disconnect.TabIndex = 10
        Me.mqtt_disconnect.Text = "Disconnect"
        Me.mqtt_disconnect.UseVisualStyleBackColor = True
        '
        'mqtt_Tx
        '
        Me.mqtt_Tx.Location = New System.Drawing.Point(609, 313)
        Me.mqtt_Tx.Name = "mqtt_Tx"
        Me.mqtt_Tx.Size = New System.Drawing.Size(144, 29)
        Me.mqtt_Tx.TabIndex = 11
        Me.mqtt_Tx.Text = "TX Message"
        Me.mqtt_Tx.UseVisualStyleBackColor = True
        '
        'Label5
        '
        Me.Label5.AutoSize = True
        Me.Label5.Location = New System.Drawing.Point(12, 127)
        Me.Label5.Name = "Label5"
        Me.Label5.Size = New System.Drawing.Size(86, 20)
        Me.Label5.TabIndex = 12
        Me.Label5.Text = "Sat in View "
        '
        'mqtt_tx_topic
        '
        Me.mqtt_tx_topic.Location = New System.Drawing.Point(12, 260)
        Me.mqtt_tx_topic.Name = "mqtt_tx_topic"
        Me.mqtt_tx_topic.Size = New System.Drawing.Size(570, 27)
        Me.mqtt_tx_topic.TabIndex = 13
        '
        'mqtt_tx_payload
        '
        Me.mqtt_tx_payload.Location = New System.Drawing.Point(12, 314)
        Me.mqtt_tx_payload.Multiline = True
        Me.mqtt_tx_payload.Name = "mqtt_tx_payload"
        Me.mqtt_tx_payload.Size = New System.Drawing.Size(570, 27)
        Me.mqtt_tx_payload.TabIndex = 14
        '
        'Label6
        '
        Me.Label6.AutoSize = True
        Me.Label6.Location = New System.Drawing.Point(12, 237)
        Me.Label6.Name = "Label6"
        Me.Label6.Size = New System.Drawing.Size(66, 20)
        Me.Label6.TabIndex = 15
        Me.Label6.Text = "Topic TX"
        '
        'Label7
        '
        Me.Label7.AutoSize = True
        Me.Label7.Location = New System.Drawing.Point(12, 291)
        Me.Label7.Name = "Label7"
        Me.Label7.Size = New System.Drawing.Size(79, 20)
        Me.Label7.TabIndex = 16
        Me.Label7.Text = "Payload Tx"
        '
        'Label8
        '
        Me.Label8.AutoSize = True
        Me.Label8.Location = New System.Drawing.Point(12, 427)
        Me.Label8.Name = "Label8"
        Me.Label8.Size = New System.Drawing.Size(83, 20)
        Me.Label8.TabIndex = 20
        Me.Label8.Text = "Payload RX"
        '
        'Label9
        '
        Me.Label9.AutoSize = True
        Me.Label9.Location = New System.Drawing.Point(12, 373)
        Me.Label9.Name = "Label9"
        Me.Label9.Size = New System.Drawing.Size(67, 20)
        Me.Label9.TabIndex = 19
        Me.Label9.Text = "Topic RX"
        '
        'MqttPayloadRx
        '
        Me.MqttPayloadRx.Location = New System.Drawing.Point(12, 450)
        Me.MqttPayloadRx.Multiline = True
        Me.MqttPayloadRx.Name = "MqttPayloadRx"
        Me.MqttPayloadRx.Size = New System.Drawing.Size(570, 127)
        Me.MqttPayloadRx.TabIndex = 18
        '
        'MqttTopicRx
        '
        Me.MqttTopicRx.Location = New System.Drawing.Point(12, 396)
        Me.MqttTopicRx.Name = "MqttTopicRx"
        Me.MqttTopicRx.Size = New System.Drawing.Size(570, 27)
        Me.MqttTopicRx.TabIndex = 17
        '
        'Button1
        '
        Me.Button1.Location = New System.Drawing.Point(609, 394)
        Me.Button1.Name = "Button1"
        Me.Button1.Size = New System.Drawing.Size(144, 29)
        Me.Button1.TabIndex = 21
        Me.Button1.Text = "Register Topic RX"
        Me.Button1.UseVisualStyleBackColor = True
        '
        'inizio
        '
        Me.inizio.AutoSize = True
        Me.inizio.Location = New System.Drawing.Point(610, 359)
        Me.inizio.Name = "inizio"
        Me.inizio.Size = New System.Drawing.Size(17, 20)
        Me.inizio.TabIndex = 22
        Me.inizio.Text = "0"
        '
        'fine
        '
        Me.fine.AutoSize = True
        Me.fine.Location = New System.Drawing.Point(613, 438)
        Me.fine.Name = "fine"
        Me.fine.Size = New System.Drawing.Size(17, 20)
        Me.fine.TabIndex = 23
        Me.fine.Text = "0"
        '
        'Label10
        '
        Me.Label10.AutoSize = True
        Me.Label10.Location = New System.Drawing.Point(589, 127)
        Me.Label10.Name = "Label10"
        Me.Label10.Size = New System.Drawing.Size(100, 20)
        Me.Label10.TabIndex = 24
        Me.Label10.Text = "Station Name"
        '
        'StationName
        '
        Me.StationName.Location = New System.Drawing.Point(589, 150)
        Me.StationName.Name = "StationName"
        Me.StationName.Size = New System.Drawing.Size(125, 27)
        Me.StationName.TabIndex = 25
        Me.StationName.Text = "Iu2IOL"
        '
        'MqttBox
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(8.0!, 20.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.ClientSize = New System.Drawing.Size(756, 589)
        Me.Controls.Add(Me.StationName)
        Me.Controls.Add(Me.Label10)
        Me.Controls.Add(Me.fine)
        Me.Controls.Add(Me.inizio)
        Me.Controls.Add(Me.Button1)
        Me.Controls.Add(Me.Label8)
        Me.Controls.Add(Me.Label9)
        Me.Controls.Add(Me.MqttPayloadRx)
        Me.Controls.Add(Me.MqttTopicRx)
        Me.Controls.Add(Me.Label7)
        Me.Controls.Add(Me.Label6)
        Me.Controls.Add(Me.mqtt_tx_payload)
        Me.Controls.Add(Me.mqtt_tx_topic)
        Me.Controls.Add(Me.Label5)
        Me.Controls.Add(Me.mqtt_Tx)
        Me.Controls.Add(Me.mqtt_disconnect)
        Me.Controls.Add(Me.SatInViewPayload)
        Me.Controls.Add(Me.Label4)
        Me.Controls.Add(Me.Label3)
        Me.Controls.Add(Me.Label2)
        Me.Controls.Add(Me.Label1)
        Me.Controls.Add(Me.MqttPassword)
        Me.Controls.Add(Me.MqttUser)
        Me.Controls.Add(Me.MqttPort)
        Me.Controls.Add(Me.MqttUrl)
        Me.Controls.Add(Me.Connect)
        Me.Name = "MqttBox"
        Me.Text = "SophyaiGsDesktop v 0.1 alfa"
        Me.ResumeLayout(False)
        Me.PerformLayout()

    End Sub

    Friend WithEvents Connect As Button
    Friend WithEvents MqttUrl As TextBox
    Friend WithEvents MqttPort As TextBox
    Friend WithEvents MqttUser As TextBox
    Friend WithEvents MqttPassword As TextBox
    Friend WithEvents Label1 As Label
    Friend WithEvents Label2 As Label
    Friend WithEvents Label3 As Label
    Friend WithEvents Label4 As Label
    Friend WithEvents SatInViewPayload As TextBox
    Friend WithEvents Timer1 As Timer
    Friend WithEvents mqtt_disconnect As Button
    Friend WithEvents mqtt_Tx As Button
    Friend WithEvents Label5 As Label
    Friend WithEvents mqtt_tx_topic As TextBox
    Friend WithEvents mqtt_tx_payload As TextBox
    Friend WithEvents Label6 As Label
    Friend WithEvents Label7 As Label
    Friend WithEvents Label8 As Label
    Friend WithEvents Label9 As Label
    Friend WithEvents MqttPayloadRx As TextBox
    Friend WithEvents MqttTopicRx As TextBox
    Friend WithEvents Button1 As Button
    Friend WithEvents inizio As Label
    Friend WithEvents fine As Label

    Private Sub Label10_Click(sender As Object, e As EventArgs) Handles Label10.Click

    End Sub

    Private Sub TextBox1_TextChanged(sender As Object, e As EventArgs) Handles StationName.TextChanged

    End Sub

    Private Sub mqtt_tx_topic_TextChanged(sender As Object, e As EventArgs) Handles mqtt_tx_topic.TextChanged

    End Sub

    Private Sub mqtt_tx_topic_Click(sender As Object, e As EventArgs) Handles mqtt_tx_topic.Click
        mqtt_tx_topic.Text = "sophyaispace/" + Me.MqttUser.Text + "/" + Me.StationName.Text
    End Sub
End Class

