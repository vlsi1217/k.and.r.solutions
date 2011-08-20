Vagrant::Config.run do |config|
  config.vm.box = "lucid32"
  config.vm.box_url = "http://files.vagrantup.com/lucid32.box"
  config.vm.network "192.168.6.17"

  Vagrant::Config.run do |config|
    config.vm.provision \
      :shell,
      :inline => "su vagrant -c 'cd /vagrant && ./Vagrant.sh'"
  end
end

