Vagrant::Config.run do |config|
  config.vm.box = "lucid32"
  config.vm.box_url = "http://files.vagrantup.com/lucid32.box"

  Vagrant::Config.run do |config|
    config.vm.provision :shell, :path => "Vagrant.sh"
  end
end

